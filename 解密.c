#include <stdio.h>
#include <string.h>
int main() {
	int a, b, c, d, e, f, g;
	int amy[1000], bmy[1000];
	char my[1000];
	gets(my);          //取得密文my
	b = strlen(my);    //获得字符串长度6-10
	c = b / 2;         //求余获得中间数
	if (b > 10)        //创造解密变量f和g，若变量太大会容易导致解密失误。(11-15)
		f = b / 10 + 3;
	else
		f = b;
	g = f / 2;
	for (a = 0; a < c; a++) { //加密前半段密文并输出
		amy[a] = my[a];  //将前半段密文（my）赋给amy进行加密
		amy[a] = amy[a] - f; //对amy进行解密
		if (amy[a] < 32) //对超出ASCII码字符区域(少于32)的字符进行重新引导至126，形成字符的闭环
			amy[a] = 126 - (32 - amy[a]);
		printf("%c", amy[a]);  //输出后半段明文amy

	}
	if (b / 2 == 0)     //变量b用于取得后半段密文的真实长度，否则自动在数组之后补上的0会对加密解密造成影响
		d = 2 * c;
	else
		d = 2 * c + 1;
	for (e = c; c <= e && e < d; e++) { //加密后半段密文并输出
		bmy[e] = my[e];   //将后半段(my)赋给bmy
		bmy[e] = bmy[e] - g;  //对bmy进行解密
		if (bmy[e] < 32)   //对超出ASCII码字符区域(少于32)的字符进行重新引导至126，形成字符的闭环
			bmy[e] = 126 - (32 - bmy[e]);
		printf("%c", bmy[e]);  //输出后半段明文bmy
	}
}
