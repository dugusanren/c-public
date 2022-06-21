#include <stdio.h>
#include <string.h>
int main() {
	int a, b, c, d, e, f, g;
	int amw[1000], bmw[1000];
	char mw[1000];
	printf("********************************************************************\n");
	printf("*                       欢迎使用简易加密系统                       *\n");
	printf("********************************************************************\n");
	printf("请输入需要加密的文本内容(字符数量小于500，且仅支持英文字符及数字):\n");
	gets(mw);         //获得加密字符串
	b = strlen(mw);   //获得字符串长度
	c = b / 2;        //求余获得中间数
	if (b > 10)       //创造加密变量f和g，若变量太大会容易导致加密失误。(11-15)
		f = b / 10 + 3;
	else
		f = b;
	g = f / 2;
	for (a = 0; a < c; a++) { //加密前半段明文并输出
		amw[a] = mw[a]; //将前半段明文（mw）赋给amw进行加密
		amw[a] = amw[a] + f; //对amw进行加密
		if (amw[a] >= 126) //对超出ASCII码字符区域(超过126)的字符进行重新引导至32，形成字符的闭环
			amw[a] = 32 + (amw[a] - 126);
		printf("%c", amw[a]); //输出前半段明文amw
	}

	if (b / 2 == 0)   //变量b用于取得后半段明文的真实长度，否则自动在数组之后补上的0会对加密解密造成影响
		d = 2 * c;
	else
		d = 2 * c + 1;

	for (e = c; c <= e && e < d; e++) { //加密后半段明文并输出
		bmw[e] = mw[e]; //将后半段(mw)赋给bmw
		bmw[e] = bmw[e] + g; //对bmw进行加密
		if (bmw[e] >= 126) //对超出ASCII码字符区域(超过126)的字符进行重新引导至32，形成字符的闭环
			bmw[e] = 32 + (bmw[e] - 126);
		printf("%c", bmw[e]); //输出后半段明文bmw
	}
}
