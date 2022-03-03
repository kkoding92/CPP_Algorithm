#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str1;
string str2;

// �ּ� ���� �Ÿ�(Edit Distance) ����� ���� ���̳��� ���α׷���
int editDist(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    // ���̳��� ���α׷����� ���� 2���� DP ���̺� �ʱ�ȭ
    vector<vector<int> > dp(n + 1, vector<int>(m + 1));

    // DP ���̺� �ʱ� ����
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }

    // �ּ� ���� �Ÿ� ���
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // ���ڰ� ���ٸ�, ���� ���� �ش��ϴ� ���� �״�� ����
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // ���ڰ� �ٸ��ٸ�, �� ���� ��� �߿��� �ּڰ� ã��
            else { // ����(����), ����(����), ��ü(���� ��) �߿��� �ּ� ����� ã�� ����
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }

    return dp[n][m];
}

int main(void) {
    cin >> str1 >> str2;

    // �ּ� ���� �Ÿ� ���
    cout << editDist(str1, str2) << '\n';
}