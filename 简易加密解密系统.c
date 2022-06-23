#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int jiami();
int jiemi();
int main() {
	while (1) {
		system("cls");    //运行前清屏，使完成引用函数回到主函数时不混乱
		char a;
		printf("********************************************************************\n");
		printf("*                       欢迎使用简易加密系统v0.3.3                 *\n");
		printf("*                      个人创意,未经允许，禁止盗用！               *\n");
		printf("*                              b.备注                              *\n");		
		printf("*                              1.加密                              *\n");
		printf("*                              2.解密                              *\n");
		printf("*                              3.退出                              *\n");		
		printf("********************************************************************\n");
		printf("请选择您要进行的操作：");
		scanf("%c", &a);        //接收选择结果

		while (1) {
			switch (a) {
				case 'b':       //跳转到加密函数
					printf("本次源代码已放到github个人公开库https://github.com/dugusanren/c-public，经过本人同意即可引用(作者微信：R11401)。\n");
					break;				
				case '1':       //跳转到加密函数
					jiami();
					break;
				case '2':       //跳转到解密函数
					jiemi();
					break;
				case '3':       //打破循环结束程序
					exit(0);
			}
			system("pause");    //在子函数结束时停顿，等待操作（复制结果等）
			break;            
		}
	}
}
int jiami() {
	int a, b, c, d, e, f, g;
	int amw[1000], bmw[1000];
	char mw[1000];
	printf("请输入需要加密的文本内容(字符数量小于500，且仅支持英文字符及数字):\n");
    fflush(stdin);	
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
	printf("\n");
	return 0;
}

int jiemi() {
	int a, b, c, d, e, f, g;
	int amy[1000], bmy[1000];
	char my[1000];
	printf("请输入需要解密的文本内容(字符数量小于500，且仅支持英文字符及数字):\n");
	fflush(stdin);	
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
	printf("\n");
	return 0;
}
