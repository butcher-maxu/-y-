#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int q[N];
void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int x = q[(r + l) / 2], i = l - 1, j = r + 1; //分界点：l r (l+r)/2 随机
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j); // 取j 分界点不能取q[r]  取i分界点不能取去q[l]
    quick_sort(q, j + 1, r);
}

int main()
{
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);

    return 0;
}