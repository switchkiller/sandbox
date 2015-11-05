//------------------------------------------------------------
/// \file	Main.cpp
/// \author	Rob Bateman
/// \date	9-feb-2005
/// \brief	Well then, linked lists. erm, they are not actually
///			very good in the land of computer games. The problem
///			is that :
///
///			a) they allocate and deallocate a fair amount of
///			   memory at runtime. These allocations have a *fair*
///			   amount of overhead.
///			b) small allocations of memory can often become
///			   fragmented - ie, small fragments occur all over
///			   the place. Traversing this sort of data tends
///			   to be slow since it's not easy to cache it.
///			c) Ideally when rendering we want to batch all of
///			   the data to be drawn in a single call. Using
///			   seperate glVertex calls is going to be a bit slow.
///
///			In practice if we want speed, it normally means we
///			need the most linear access to data available - arrays.
///			Accessing the data linearly helps with caching and
///			thus also speeds up the code. One downside to an
///			array is that reallocating it can be very costly!
///
///			Well, the only way to really handle this is to
///			impliment our own cunning memory management trickery.
///			Heres how it will work:
///
///			A single large allocation of memory will be made.
///			I store a pointer to the beginning of the allocation,
///			start; a pointer to the very end of the allocation,
///			end and finally, a pointer to the next free space
///			in the array.
///
///			For example, initially after the block of memory
///			has been allocated, both start and last point to
///			the start of the block since it's empty.
///
///			When we add a new element into the array, we add it
///			where last is currently referencing and then move
///			last to the next memory location.
///
///			So after a while our array fills up, and then we
///			decide we want to remove some item from the array.
///			To do this, we simply copy the last element over
///			the element to be removed and move last back an item
///			in the array.
///
///			Using this technique, we maintain all particles
///			tighly packed at the beginning of the array with
///			no gaps. We also are able to add and remove particles
///			without the overhead of memory allocations. We need
///			to make sure we dont go above our static array
///			allocation, but thats  a small price to pay.
///
///			You may be asking why i dont store the number of
///			particles, the answer is :
///
///				num_particles = last - start;
///
///
//------------------------------------------------------------

#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
//s#include "FrameTimer.h"

/// a structure to hold a particle
struct Particle {

	/// the current particle position
	float position[3];

	/// the direction of the particle
	float direction[3];

	/// the colour of the particle
	float colour[3];

	/// the lifespan
	float life;

	/// constructor
	Particle();
};

/// the first particle in the linked list
Particle* start=0;

/// the next free particle
Particle* last=0;

/// the end of the memory allocation
Particle* end=0;


//------------------------------------------------------------	SetSize()
//
//	Allocates the static global particle buffer
//
void SetSize(unsigned int size) {

	// delete any previous data
	delete [] start;

	// allocate new particles
	last = start = new Particle[size];

	// set end
	end = start+size;
}


//------------------------------------------------------------	IsEmpty()
//
//	returns true if the particle array is empty
//
bool IsEmpty() {
	return start==last;
}

//------------------------------------------------------------	IsFull()
//
//	returns true if the array is full
//
bool IsFull() {
	return last==end;
}

//------------------------------------------------------------	DrawParticles()
//
void DrawParticles() {

	// since the particles are all nicely packed into one place,
	// i can simply use vertex arrays to render the data. To do
	// this we need to give the address of the first data element
	// in the array. We also need to specify a stride parameter,
	// ie the number of bytes between each data element. In this
	// case, each position is seperated by another particle. The
	// same is true of the colours.
	//
	//
	glVertexPointer(3,GL_FLOAT,sizeof(Particle),start->position);
	glColorPointer(3,GL_FLOAT,sizeof(Particle),start->colour);

	// enable vertex arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// draw the particles in one lovely function call. Note that
	// this is faster than glBegin/glEnd() because it avoids the
	// large amount of function call overhead.
	//
	glDrawArrays(GL_POINTS,0,last-start);

	// disable vertex arrays
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}


//------------------------------------------------------------	AddOne()
// this function 'adds' a particle into the array. In actual
// fact, all it does is move the pointer to the last element
// along by one position. This means we have not performed an
// expensive memory allocation.
//
void AddOne() {

	// if we have no more memory left for any particles, ignore
	// the request to creat one.
	if (!IsFull()) {
		*last = Particle();
		++last;
	}
}

//------------------------------------------------------------	EraseOne()
// Given a pointer to the particle that needs to be deleted,
// this function simply swaps the last particle with the one
// to be deleted. This means that all living particles are
// always tightly packed at the front of the array, and
// secondly we have no need to perform any memory allocations
//
void EraseOne(Particle* p) {
	if (!IsEmpty()) {
		*p = *(--last);
	}
}



//------------------------------------------------------------	Particle::Particle()
/// constructor
Particle::Particle() {

	// set position
	position[0] = position[2] = 0.0f;
	position[1] = 0.0f;

	// create random direction
	direction[0] = (10000 - rand()%20000)/10000.0f;
	direction[1] = (10000 - rand()%20000)/10000.0f;
	direction[2] = (10000 - rand()%20000)/10000.0f;

	// create random colour
	colour[0] = 0.8f;
	colour[1] = rand()%15000/20000.0f;
	colour[2] = 0.1f;

	// set a random lifespan
	life = rand()%30000/9500.0f;
}

//------------------------------------------------------------	UpdateParticles()
//
void UpdateParticles(float dt) {

	// traverse all particles and update
	Particle* p = start;
	while(p!=last) {
		// decrease lifespan
		p->life -= dt;

		// if we have life left
		if (p->life>0) {

			// apply gravity
			p->direction[1] -= 1.31f*dt;

			// modify position
			p->position[0] += dt * p->direction[0];
			p->position[1] += dt * p->direction[1];
			p->position[2] += dt * p->direction[2];

			p->colour[0] *= (1-0.3*dt);
			p->colour[1] *= (1-0.3*dt);
			p->colour[2] *= (1-0.3*dt);

			// goto next particle
			++p;
		}
		else {
			// if the particle is dead, erase it
			EraseOne(p);

			// make sure it wasn't the last particle in the array,
			// if it was, return
			if (p>=last) {
				return;
			}
		}

	}
}

//------------------------------------------------------------	OnReshape()
//
void OnReshape(int w, int h)
{
	// prevents a division by zero when calculating aspect
	// ratio below. This can happen when the window gets
	// minimised.
	if (h==0)
		h=1;

	// set the drawable region of the window
	glViewport(0,0,w,h);

	// set up the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// just use a perspective projection
	gluPerspective(45,(float)w/h,0.1,100);

	// go back to modelview matrix so we can move the objects about
	glMatrixMode(GL_MODELVIEW);
}

//------------------------------------------------------------	Draw()
//
void OnDraw() {

	// clear the screen & depth buffer
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

	// clear the previous transform
	glLoadIdentity();

	// set the camera position
	gluLookAt(	1,-3,10,	//	eye pos
				0,-3,0,	//	aim point
				0,1,0);	//	up direction

	//
	DrawParticles();

	// currently we've been drawing to the back buffer, we need
	// to swap the back buffer with the front one to make the image visible
	glutSwapBuffers();
}

//------------------------------------------------------------	OnInit()
//
void OnInit() {
	// enable depth testing
	glEnable(GL_DEPTH_TEST);

	// set the maximum number of particles
	SetSize(100000);
}

//------------------------------------------------------------	OnExit()
//
void OnExit() {
}

// used for frame counting
int count=0;

//------------------------------------------------------------	OnIdle()
//
void OnIdle() {

	if(++count == 1000) {
		std::cout << "num particles = " << ((int)(last-start)) << "   fps = " << (1.0f/FrameTime())<< "\n";
		count=0;
	}

	// update the frame time
	SortFrameTimer();

	// create a random number of new particles every frame
	int val = rand()%1000;
	for(int i=0;i!=val;++i)
		AddOne();

	// update the particle simulation
	UpdateParticles(FrameTime());

	// redraw the screen
	glutPostRedisplay();
}


//------------------------------------------------------------	main()
//
int main(int argc,char** argv) {

	// initialise glut
	glutInit(&argc,argv);

	// request a depth buffer, RGBA display mode, and we want double buffering
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE);

	// set the initial window size
	glutInitWindowSize(640,480);

	// create the window
	glutCreateWindow("A basic glut example");

	// set the function to use to draw our scene
	glutDisplayFunc(OnDraw);

	// set the function to handle changes in screen size
	glutReshapeFunc(OnReshape);

	// set the idle callback
	glutIdleFunc(OnIdle);

	// run our custom initialisation
	OnInit();

	// set the function to be called when we exit
	atexit(OnExit);

	// initialise the frame timer
	InitFrameTimer();

	// this function runs a while loop to keep the program running.
	glutMainLoop();
	return 0;
}
