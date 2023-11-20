#include<bits/stdc++.h>
using namespace std;

//int tree[] = {3, 12, 8, 4, 4, 6, 14, 6, 7};


/*int tree[]={41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 91, 95, 42, 27, 36, 91, 4, 2, 53, 92, 82, 21, 16, 18, 95, 47, 26,
 71, 38, 69, 12, 67, 99, 35, 94, 3, 11, 22, 33, 73, 64, 41, 11, 53, 68, 47, 44, 62, 57, 37, 59, 23, 41, 29, 78, 16, 35, 90, 42, 88, 6,
 40, 42, 64, 48, 46, 5, 90, 29, 70, 50, 6, 1, 93, 48, 29};

int tree[] ={41, 43, 62, 40, 59, 44, 12, 56, 12, 62, 21, 19, 55, 69, 63, 1, 55, 84, 25, 46, 51, 2, 80, 55, 96, 34, 75, 96, 20, 1, 57, 68,
71, 72, 7, 18, 89, 35, 81, 94, 87, 95, 60, 51, 33, 58, 49, 67, 29, 8, 67, 8, 28, 25, 45, 21, 1, 39, 89, 92, 66, 95, 42, 78, 92, 20, 24, 24,
56, 10, 6, 89, 14, 65, 66, 62, 12, 35, 89, 20, 29};

*/
int tree[] = {41, 17, 20, 14, 63, 62, 80, 2, 66, 28, 47, 19, 75, 17, 39, 81, 43, 52, 71, 24, 1, 8, 48, 71, 46, 0, 37, 20, 38, 51, 35, 78, 11,
58, 65, 68, 1, 59, 61, 54, 3, 31, 80, 75, 43, 72, 53, 3, 45, 62, 45, 10, 26, 39, 29, 67, 31, 65, 59, 40, 16, 1, 50, 38, 42, 12, 20, 4, 76, 16,
58, 25, 64, 5, 16, 16, 0, 23, 39, 22, 31};


int MX = 1e7;
int MN = -1e7;
int alphabetapruning(int index, int d, int mxmn, int alpha, int beta)
{
    if (d == 0) return tree[index];
    if (mxmn%2==0){
        int maximum = MN;
        for (int i = 0; i < 3; i++){
            maximum = max(maximum, alphabetapruning(index * 3 + i, d - 1, mxmn+1, alpha, beta));
            alpha = max(alpha, maximum);

            if (alpha >= beta) break;
        }
        return maximum;
    }
    else{
        int minimum = MX;
        for (int i = 0; i < 3; i++){
            minimum = min(minimum, alphabetapruning(index * 3 + i, d - 1, mxmn+1, alpha, beta));
            beta = min(beta, minimum);

            if (alpha >= beta) break;
        }
        return minimum;
    }
}

int main()
{
    int height=4;
    cout <<"Final value is : "<< alphabetapruning(0, height, 0, MN, MX);
    return 0;
}
