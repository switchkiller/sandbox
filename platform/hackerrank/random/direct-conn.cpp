#include <iostream>
using namespace std;
#define N 10000
struct arr{
	int v1;
	int v2;
}ar[2*N];

void init(int n){
	for (int i = 0; i < n; i++){
		ar[i].v1 = 0;
		ar[i].v2 = 0;
	}
}

void swap(struct arr* a, struct arr* b)
{
    struct arr t = *a;
    *a = *b;
    *b = t;
}

int partition (struct arr ar[], int low, int high)
{
    int pivot = ar[high].v2;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (ar[j].v2 > pivot)
        {
            i++;
            swap(&ar[i], &ar[j]);
        }
    }
    swap(&ar[i + 1], &ar[high]);
    return (i + 1);
}

void quickSort(struct arr ar[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(ar, low, high);
        quickSort(ar, low, pi - 1);
        quickSort(ar, pi + 1, high);
    }
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		init(n);
		long long sum = 0;
		for (int i = 0; i < n; i++){
			cin >> ar[i].v1;
			sum += ar[i].v1;
		}
		for (int i = 0; i < n; i++)
			cin >> ar[i].v2;
		quickSort(ar, 0, n-1);
		long long result = 0;
		for (int i = 0; i < n-1; i++){
			result += ar[i].v2 *  (ar[i].v1 * (n-i+1) - sum - ar[i].v1);
			sum -= ar[i].v1;
		}
		cout << result << endl;
	}
	return 0;
}
