// Good approach but, A and B size are huge :o
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int mapA[7], mapB[7];
        memset(mapA, 0, sizeof mapA);
        memset(mapB, 0, sizeof mapB);
        for (int i = 0; i < A.size(); i++){
            int valA = A[i], valB = B[i];
            mapA[valA] = mapA[valA] | (1 << i);
            mapB[valB] = mapB[valB] | (1 << i);
        }

        for (int i = 1; i <= 6; i++){
            if ((mapA[i] | mapB[i]) == ((1 << n) - 1)){
                int cntA = 0, cntB = 0;
                for (int j = 0; j < n; j++){
                    int x = 1 << j;
                    if ((x & mapA[i]) == 0)
                        cntA++;
                    if ((x & mapB[i]) == 0)
                        cntB++;
                }
                return min(cntA,cntB);
            }
        }
        return -1;
    }
};
