/*
2 -1 1
-4 3 -3
-2 3 2
*/
#include <stdio.h>
int a[50][50], rez[50], b[50][50], c[50][50];
int main()
{
	printf("Introduceti dimensiunile matricei:\n");
	int n, p;
	scanf("%d%d",&n,&p);
	printf("Introduceti elementele matricei:\n");
	for(int i=1; i<=n; i++)
		for(int j=1; j<=p; j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j]=c[i][j]=a[i][j];
		}
	printf("Introduceti termenii liberi\n");
		for(int i=1; i<=n; i++)
			scanf("%d",&rez[i]);
	if(n==p)
	{
		int Delta=0;
		if(n==2)
			Delta=a[1][1]*a[2][2]-a[1][2]*a[2][1];
		else
			if(n==3)
				Delta=a[1][1]*a[2][2]*a[3][3]+a[1][2]*a[2][3]*a[3][1]+a[1][3]*a[2][1]*a[3][2]-
			a[1][3]*a[2][2]*a[3][1]-a[1][1]*a[2][3]*a[3][2]-a[1][2]*a[2][1]*a[3][3];
		if(Delta!=0) printf("Sistem Cramer: ");
		printf("%d\n",Delta);
		int cnt=1;
		if(n==3)
		{	
			int cnt=1;
			int x, y, z;
			for(int i=1; i<=n; i++)
				a[i][cnt]=rez[i];
				
			int Dx=a[1][1]*a[2][2]*a[3][3]+a[1][2]*a[2][3]*a[3][1]+a[1][3]*a[2][1]*a[3][2]-
			a[1][3]*a[2][2]*a[3][1]-a[1][1]*a[2][3]*a[3][2]-a[1][2]*a[2][1]*a[3][3];
			printf("%d ",Dx/Delta);
			cnt++;

			for(int i=1; i<=n; i++)
				b[i][cnt]=rez[i];
				
			int Dy=b[1][1]*b[2][2]*b[3][3]+b[1][2]*b[2][3]*b[3][1]+b[1][3]*b[2][1]*b[3][2]-
			b[1][3]*b[2][2]*b[3][1]-b[1][1]*b[2][3]*b[3][2]-b[1][2]*b[2][1]*b[3][3];
			printf("%d ",Dy/Delta);
			cnt++;

			for(int i=1; i<=n; i++)
				c[i][cnt]=rez[i];
				
			int Dz=c[1][1]*c[2][2]*c[3][3]+c[1][2]*c[2][3]*c[3][1]+c[1][3]*c[2][1]*c[3][2]-
			c[1][3]*c[2][2]*c[3][1]-c[1][1]*c[2][3]*c[3][2]-c[1][2]*c[2][1]*c[3][3];
			printf("%d ",Dz/Delta);
		}
	}
	return 0;
}