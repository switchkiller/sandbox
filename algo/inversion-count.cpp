// Leetcode solution to globalInversion and localInversion

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int globalInversion, localInversion = 0;
        vector<int> B(10000,0);
        for  (int i = 1; i < A.size(); i++){
            if (A[i] < A[i-1]){
                localInversion++;
            }
        }
        globalInversion = inversionCount(A, B, 0, A.size()-1);

        if (globalInversion == localInversion)
            return true;
        return false;
    }

    int inversionCount(vector<int>& A, vector<int>& B, int low, int high){
        int mid, inv_count = 0;
        if (high > low){
            mid = low + (high-low)/2;
            inv_count += inversionCount(A, B, low, mid);
            inv_count += inversionCount(A, B, mid+1, high);

            inv_count += merge(A, B, low, mid, high);
        }
        return inv_count;
    }

    int merge(vector<int>& A, vector<int>& B, int low, int mid, int high){
        int inv_count = 0;

        int i = low, j = mid+1, k = low;
        while(i <= mid && j <= high){
            if (A[i] <= A[j]){
                B[k] = A[i];
                i++; k++;
            } else if (A[j] < A[i]){
                B[k] = A[j];
                j++; k++;
                inv_count += (mid-i+1);
            }
        }

        while(i <= mid){
            B[k] = A[i];
            i++; k++;
        }

        while(j <= high){
            B[k] = A[j];
            k++; j++;
        }

        for (i = low; i <= high; i++){
             A[i] = B[i];
        }

        return inv_count;
    }

};
