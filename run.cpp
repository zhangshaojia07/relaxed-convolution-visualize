//https://www.zhihu.com/question/30262900/answer/48741026
#include<bits/stdc++.h>
using namespace std;
#define rep(Ii,Jj,Kk) for(int Ii=(Jj),Ii##_=(Kk);Ii<=Ii##_;Ii++)
#define per(Ii,Jj,Kk) for(int Ii=(Jj),Ii##_=(Kk);Ii>=Ii##_;Ii--)

const int DIM=512,L=15,B=3;
#define uc unsigned char
uc f[DIM][DIM][3];
void show(){
	static int cnt=0;
	FILE *fp=fopen(("./data/"+to_string(cnt++)+".ppm").c_str(),"wb");
	fprintf(fp,"P6\n%d %d\n255\n",DIM,DIM);
	per(j,DIM-1,0) rep(i,0,DIM-1) fwrite(f[i][j], 1, 3, fp);
	fclose(fp);
}
void o(int x,int y,int xx,int yy,uc a,uc b,uc c){
	rep(i,x,xx-1) rep(j,y,yy-1) f[i][j][0]=a,f[i][j][1]=b,f[i][j][2]=c;
}
void mul(int x,int y,int len,string col="grey"){
	int xx=x+len,yy=y+len;
	uc a,b,c;
	if(col=="grey") a=20,b=20,c=20;
	else if(col=="green") a=20,b=150,c=20;
	else if(col=="red") a=150,b=20,c=20;
	else if(col=="blue") a=20,b=20,c=150;
	o(2*L+x*L+B,2*L+y*L+B,2*L+xx*L-B,2*L+yy*L-B,a,b,c);
}
/*
void slv(int l,int r){// 左闭右开
	if(l+1==r){
		mul(l,0,1);
		show();
		if(l!=31){
			rep(i,0,l) mul(i,l-i,1,"green");
			mul(l+1,-2,1,"green");
			show();
			rep(i,0,l) mul(i,l-i,1,"grey");
		}
		return ;
	}
	int mid=(l+r)>>1,len=mid-l;
	slv(l,mid);
	mul(l,len,len);
	show();
	slv(mid,r);
	mul(mid,len,len);
	show();
}
*/
void work(int l,int r){
	if(l+1==r){
		mul(l,0,1);
		mul(0,l,1);
		show();
		if(l!=31){
			rep(i,0,l) mul(i,l-i,1,"green");
			mul(l+1,-2,1,"green");
			mul(-2,l+1,1,"green");
			show();
			rep(i,0,l) mul(i,l-i,1,"grey");
		}
		return ;
	}
	int mid=(l+r)>>1,len=mid-l;
	work(l,mid);
	mul(l,len,len);
	mul(len,l,len);
	show();
	work(mid,r);
	mul(mid,len,len);
	mul(len,mid,len);
	show();
}
int main(){
	rep(i,0,DIM-1) rep(j,0,DIM-1) rep(k,0,2) f[i][j][k]=255;
	o(2*L-B,2*L-B,2*L,DIM,0,0,0);
	o(2*L-B,2*L-B,DIM,2*L,0,0,0);
	/*
	rep(i,0,31){
		mul(-2,i,1,"green");
		mul(i,-2,1,"red");
	}
	mul(0,-2,1,"green");
	show();
	slv(0,32);
	*/
	rep(i,0,31){
		mul(-2,i,1,"red");
		mul(i,-2,1,"red");
	}
	mul(0,-2,1,"green");
	mul(-2,0,1,"green");
	show();
	mul(0,0,1);
	show();
	mul(0,0,1,"green");
	mul(1,-2,1,"green");
	mul(-2,1,1,"green");
	show();
	mul(0,0,1,"grey");
	for(int i=1;i!=32;i<<=1){
		work(i,i<<1);
		mul(i,i,i);
		show();
		// mul(0,0,i<<1,"blue");
		// show();
		// mul(0,0,i<<1,"grey");
	}
	return 0;
}
