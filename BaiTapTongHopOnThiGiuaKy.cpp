#include<iostream>
using namespace std;
void chuyenHeThapLucPhan(int n){
	if(n>0){
		int tmp = n%16;
		if(tmp <10){
			cout<<tmp;
		}else{
			char heSo = 'A' + (tmp-10);
			cout<<heSo;
		}
	}
}
void chuyenHe(int n){
	if(n>0){
		chuyenHe(n/2);
		cout<<n%2;
	}
}

int chuyenHe2(int n){
	if(n>0){
		return chuyenHe2(n/2)*10 + (n%2);
	}
}
int tongCacSoChan(int n,int sum =0){
	if(n==0) return sum;
	if(n>0){
		int tmp = n%10;
		if(tmp%2==0){
			sum = sum + tmp;
		}
		return tongCacSoChan(n/10,sum);
	}
}
int sodep(int n,int sum=0){
	if(n==0) return sum;
	if(n>0){
		int tmp = n%10;
		sum+=tmp;
		return sodep(n/10,sum%10);
	}
}
int ucln(int a,int b){
	if(b==0) return a;
	if(a>b){
		return ucln(a-b,b);
	}else{
		return ucln(a,b-a);
	}
}
void nhapMang(int a[],int &n){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}
void xuat(int a[],int end,int count){
	int begin = end - count +1;
	for(int i=begin;i<=end;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int timDayConTangLienTuc(int a[],int n){
	int ht = 1;
	int kq = 1;
	for(int i=1;i<=n-1;i++){
		if(a[i] > a[i-1]){
			ht++;
			kq =  max(ht,kq);
		}else{
			ht=1;
		}
	}
	return kq;
}
void xuatChuoiCon(int a[],int n,int &k){
	cin>>k;
	int ds = timDayConTangLienTuc(a,n);
	int ht=1;
	for(int i=1;i<=n-1;i++){
		if(a[i] >  a[i-1]){
			ht++;
		}else{
			ht=1;
		}
		if(ht>k){
			xuat(a,i,ht);
		}
	}
}
void xuatMang(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
void chenPhanTu(int a[],int n,int &vitri,int &giatri){
	cout<<"Nhap vi tri can chen: ";cin>>vitri;
	cout<<"Nhap gia tri can chen: ";cin>>giatri;
	if(vitri <0 || vitri >n){
		cout<<"Vi tri khong hop le";
	}
	for(int i=n;i>vitri;i--){
		a[i] = a[i- 1];
	}
	a[vitri] = giatri;
	n++;
}
int main(){
	int a[1000],n,k,vt,gt;
	nhapMang(a,n);
	chenPhanTu(a,n,vt,gt);
	xuatMang(a,n);
	return 0;
}
