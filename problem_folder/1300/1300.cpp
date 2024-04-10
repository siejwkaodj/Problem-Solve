#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// functions
int binSearch(int n, int k, int st, int ed);
pair<int, int> smallerNumbersCount(int x, int n);
void test(int n, int k);
void printA(int n);

int main() {
	fastio;
    int n, k;
    cin >> n >> k;

    // solving
    int ans = binSearch(n, k, 1, n * n);

    // output
    // cout << ans;

    // test
    // cout << endl;
    // cout << endl;
    printA(n);
    cout << endl;
    for(int i = 1; i <= n * n; i++){
        cout << "k: " << i << " / " << binSearch(n, i, 1, n * n) << endl;
    }

	return 0;
}

// 이진탐색으로 해당 수 x가 k번째 수인지 확인 - O(N * logN)
// 함수 자체는 O(logN)이지만 smallerNumberCount가 O(N)이라 총 시간복잡도는 O(NlogN)이 된다
int binSearch(int n, int k, int st, int ed){
    int mid = (st + ed) / 2;    // 9 16 -> 12
    pair<int, int> countResult = smallerNumbersCount(mid, n);
    int smallerCnt = countResult.first, cnt = countResult.second;
    if(st == ed) return mid;
    // smallerCnt, cnt / 13, 15
    // k - 1 = 13, 
    if(k - 1 >= cnt){
        return binSearch(n, k, mid + 1, ed);
    }else if(smallerCnt <= k - 1 && k - 1 < cnt){
        return mid;
    }else{
        return binSearch(n, k, st, mid - 1);
    }
}
// 4 1일때 k = 14, 15, 16일때 문제 발생, 각각 12 12 16이 나와야함.

// A 안에서 x보다 작은 수의 개수를 반환하는 함수 - O(N)
pair<int, int> smallerNumbersCount(int x, int n){
    int cnt = 0, smallerCnt = 0;
    for(int i = 1; i <= n; i++){
        int lineCnt = min(x / i, i * n);
        cnt += lineCnt;
        smallerCnt += lineCnt;

        if(i <= x && x <= i * n && x % i == 0){
            smallerCnt -= 1;
        }
    }
    return {smallerCnt, cnt};
}

void printA(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%3d ", i * j);
        }
        printf("\n");
    }
    return;
}
