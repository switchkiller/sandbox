import numpy as np

def PolyArea2D(pts):
    lines = np.hstack([pts,np.roll(pts,-1,axis=0)])
    area = 0.5*abs(sum(x1*y2-x2*y1 for x1,y1,x2,y2 in lines))
    return area


pts = [[0,0],[1,0],[1,1],[0,1]]
print PolyArea2D(pts)

pts = [[0,0],[1,0],[0,1]]
print PolyArea2D(pts)

pts = [[0,0],[1,0],[0.5,0.5]]
print PolyArea2D(pts)
