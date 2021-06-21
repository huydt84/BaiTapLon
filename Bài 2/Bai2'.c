# include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

void main() {
	FILE *fp;
	int val[100], wt[100], name[100], quan[100], dp[100][100];
	int i, j, n, w;
	int dem = 0;
	
	fp = fopen("bag.inp", "rb");
	
	fscanf(fp, "%d %d", &n, &w);
	while(fscanf(fp, "%d %d %c", &wt[dem], &val[dem], &name[dem]) != EOF) {
		quan[dem] = 0;
		dem++;
	}
 	
	for (i=0; i<=n; i++) {
		for(j=0; j<=w; j++){
    		dp[i][j] = 0;
    	}
	}
	
 	for (i=1; i<=n; i++) {
		for(j=1; j<=w; j++){
    		if (wt[i-1] <= j) dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
        	else dp[i][j] = dp[i-1][j];
    	}
	}
	
	int x = n;
	int y = w; 	
    while (x > 0 && y > 0) {
        if (dp[x][y] == dp[x-1][y])
            x--;
        else if (dp[x-1][y] >= dp[x][y - wt[x-1]] + val[x-1]) 
            x--;
        else {
            quan[x-1] += 1;
            y -= wt[x-1];
        }
    }
    
    printf("%d\n", dp[n][w]);
    for(i=0; i<n; i++) {
    	if (quan[i] != 0) printf("%c %d\n", name[i], quan[i]);
	}

	fclose(fp);
}
