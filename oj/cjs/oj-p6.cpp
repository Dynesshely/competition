/*
	Description
	俗话说：人比人，气死人；鱼比鱼，难死鱼。小鱼最近参加了一个“比可爱”比赛，比的是每只鱼的可爱程度。参赛的鱼被从左到右排成一排，头都朝向左边，然后每只鱼会得到一个整数数值，表示这只鱼的可爱程度，很显然整数越大，表示这只鱼越可爱，而且任意两只鱼的可爱程度可能一样。由于所有的鱼头都朝向左边，所以每只鱼只能看见在它左边的鱼的可爱程度，它们心里都在计算，在自己的眼力范围内有多少只鱼不如自己可爱呢。请你帮这些可爱但是鱼脑不够用的小鱼们计算一下。

	Format
	Input
	第一行输入一个整数 n，表示鱼的数目。

	第二行内输入 n 个整数ai，用空格间隔，依次表示从左到右每只小鱼的可爱程度。

	Output
	行内输出 n 个整数，用空格间隔，依次表示每只小鱼眼中有多少只鱼不如自己可爱。
*/

#include <bits/stdc++.h>
using namespace std;
int n, a[110];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i){
		int sum = 0;
		scanf("%d", &a[i]);
		for(int j = 1; j <= i; ++ j)
			if(a[j] < a[i]) sum ++;
		printf("%d ", sum);
	}
	printf("\n");
	return 0;
}