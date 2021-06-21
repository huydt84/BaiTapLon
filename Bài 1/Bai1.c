# include <stdio.h>

void main() {
	FILE *fp, *fw;
	long long int x, y, p, i;
	
	fp = fopen("tohop.inp", "rb+");
	fw = fopen("tohop.out", "ab+");
	while(fscanf(fp, "%lli %lli", &x, &y) != EOF )
    {
    	float k=1;
    	p = 1;
        for(i=y+1; i<=x; i++) {
        	p *= (i/k);
        	k++;
		}
		printf("%lli\n", p);
		fprintf(fw, "%lli\n", p);
	}
	fclose(fp);
	fclose(fw);
}

