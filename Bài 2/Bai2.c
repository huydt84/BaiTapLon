# include <stdio.h>

struct obj {
	char name;
    int weight;
    float value;
    int quantity;
    float quality;
};

void swap(struct obj *a, struct obj *b) {
	struct obj t = *a;
	*a = *b;
	*b = t;
}

void main() {
	FILE *fp;
	struct obj a[100];
	int i, j, n, w, k;
	int dem = 0;
	float val = 0;
	
	fp = fopen("bag.inp", "rb");
	
	fscanf(fp, "%d %d", &n, &w);
	while(fscanf(fp, "%d %f %c", &a[dem].weight, &a[dem].value, &a[dem].name) != EOF){
		a[dem].quality = a[dem].value / a[dem].weight;
		dem++;
	}
	
	for (i=0; i<n-1; i++) {
		for (j=i+1; j<n; j++) {
			if(a[i].quality < a[j].quality) swap(&a[i], &a[j]);
		}
	}
	
	for (i=0; i<n; i++) {
		a[i].quantity = w / a[i].weight;
		if (a[i].quantity != 0) {
			w %= a[i].weight;
			val += a[i].quantity * a[i].value;
		}
	}
	
	printf("%.f\n", val);
	for (i=0; i<n; i++) {
		if (a[i].quantity != 0)  {
		printf("%c %d\n", a[i].name, a[i].quantity);
		}
	}
	
	fclose(fp);
}
