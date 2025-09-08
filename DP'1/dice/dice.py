import sys

MOD = int(1e9+7)

def solve(n):
    if n == 0:
        return 1
    formas = 0
    for x in [1,2,3,4,5,6]:
        if n-x >=0:
            formas = formas + solve(n-x)
    return formas



def solve_dp(n, dp):
    if n == 0:
        return 1
    formas = 0
    for x in [1,2,3,4,5,6]:
        if n-x >=0:
            formas = formas + solve_dp(n-x, dp)
    dp[n] = formas
    return dp[n]


if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    dp= [0 for x in range(n+1)]
    dp[0] = 1

    for i in range(1, n+1):
        for x in [1,2,3,4,5,6]:
            if i-x >=0:
                dp[i] = (dp[i]+dp[i-x])%MOD   

    sys.stdout.write(str(dp[n])+"\n")
