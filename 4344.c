#include <stdio.h>
#include <math.h>

double nRound(double x, int n)
{
    if(n == 1) return round(x);
    int mul = pow(10, n - 1);
    double temp = x * mul;
    return round(temp) / mul;
}

double getAvg(int *data, int length)
{
    double result = 0;
    for(int i = 0; i < length; i++) result += data[i];
    result /= length;
    return result;
}

int numOverAvg(int *data, int length, double avg)
{
    int result = 0;
    for(int i = 0; i < length; i++) if(data[i] > avg) result++;
    return result;
}

int main(int argc, char const *argv[])
{
    int C, length, data[1001];
    
    scanf("%d", &C);
    for(int i = 0; i < C; i++)
    {
        scanf("%d", &length);
        for(int j = 0; j < length; j++) scanf("%d", &data[j]);

        double avg = getAvg(data, length);
        int temp = numOverAvg(data, length, avg);
        double pct = ((double)temp / (double)length) * 100;
        printf("%.3lf%%\n", nRound(pct, 4));
    }
    return 0;
}
