#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

std::vector<int> sum_swap(std::vector<int>& a,std::vector<int> b);

//int abs(int x);
//int sum_vector(std::vector<int>& a);


int main()
{
	 /* ?\n;||(or) e &&(and)*/


	std::vector<int> a = {4,1,2,1,1,2};
	std::vector<int> b = {3,6,3,3};
	std::vector<int> v1 = sum_swap(a,b);
	for(int i = 0;i < v1.size();i++){
		std::cout << v1[i] << " ";
	}
	std::cout << '\n';
	std::vector<int> v2 = sum_swap(b,a);
	for(int i = 0;i < v2.size();i++){
		std::cout << v2[i] << " ";
	}


	return 0;
}

int abs(int x){
	return sqrt(pow(x,2));
}

int sum_vector(std::vector<int>& a){

	int sum = 0;
	for(int i = 0;i < a.size();i++){
		sum += a[i];
	}
	return sum;
}

int binary_search(std::vector<int> &v,int x){

	int strt = 0;
	int end = v.size()-1;
	int mid;

	while(strt <= end){
		mid = (strt+end)/2;
		if(v[mid] == x){
			return mid;
		}
		if(v[mid] > x){
			//x in the left <---
			end = mid-1;
		}
		if(v[mid] < x){
			//x int he right --->
			strt = mid+1;
		}
	}
	return -1;

}

std::vector<int> sum_swap(std::vector<int>& a,std::vector<int> b){

	std::vector<int> sol;

	int sum_a = sum_vector(a);
	int sum_b = sum_vector(b);
	int m = abs(sum_a - sum_b);

	std::sort(b.begin(),b.end());//O(nlog(n))

	//if m is odd then there is no integer solution
	if(m % 2 != 0){
		std::cout << "No integer solution.";
		return sol;
	}

	//I will pick a,then use the fact that abs(x - y) = m/2 to find y by bSearch in sorted b
	if(sum_a > sum_b){
		m *= -1;
	}
	for(int i = 0;i < a.size();i++){//O(nlog(n))
		int x = a[i];
		int y = x + m/2;
		if(binary_search(b,y) != -1){
			sol.push_back(x);
			sol.push_back(y);
			return sol;
		}
	}
	std::cout << "No integer solution.";
	return sol;
}
