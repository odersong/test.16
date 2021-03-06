
//内置类型：int  char  long   longlong   double  float
//自定义类型（构造类型）:数组类型  例子:int arr[10]和int arr[5]不是一种类型
//结构体类型：struct
//枚举类型：enum
//联合类型：union


//整形家族：char, unsigned char, singed char
//int, unsigned int, signed int
//short, unsigned short, signed short
//long, unsigned long, signed long

//浮点型家族：float, double


//计算机中整形有符号数有三种表示方法，即原码，反码，补码   ,但是正数原码，反码，补码相同
//无符号数原码，反码，补码相同

//2个16进制字符表示一个字节，所以一个字节8个比特位，其中四个比特位表示一个16进制的字符

#include<stdio.h>
//int main()
//{
//	int a = 10;
//	//原码：00000000000000000000000000001010
//	//反码：00000000000000000000000000001010
//	//补码：0000 0000 0000 0000 0000 0000 0000 1010
//	//在计算机中存储：0x0000000a                     0x表示16进制
//	int b = -10;
//	//原码：10000000000000000000000000001010
//	//反码：11111111111111111111111111110101
//	//补码：11111111111111111111111111110110
//	//在计算机中存储：0xFFFFFFF6      不过计算机时倒着存储的
//	return 0;
//}


//大端存储：低位保存在高地址处，高位保存在低地址处  顺存
//小端存储：低位存储在低地址处，高位存储在高地址处  逆存     我用的vs就是小端存储
//描述的是字节的顺序，不是二进制位的顺序，一个字节表示两个16进制字符


//int main()
//{
//	int a = 20;
//	char* p = (char*) & a;
//	if (*p == 1)
//	{
//		printf("小端");
//	}
//	else
//	{
//		printf("大端");
//	}
//	return 0;
//}

//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端");
//	}
//	else
//	{
//		printf("大端");
//	}
//	return 0;
//}

//整型提升
//int main()
//{
//	char a = -1;
//	//-1的原码：10000000000000000000000000000001
//	//-1的反码：11111111111111111111111111111110
//	//-1的补码：11111111111111111111111111111111
//	//char存一个字符8个比特位：11111111
//	//打印出来需要进行整型提升：11111111111111111111111111111111,有符号位的整型提升是向左补符号位
//	//打印的是原码：10000000000000000000000000000001=-1
//	signed char b = -1;//这个也是有符号位的-1
//	//11111111
//	//11111111111111111111111111111111
//	//10000000000000000000000000000001=-1
//	unsigned char c = -1;//无符号位向左补0
//	//11111111
//	//00000000000000000000000011111111,无符号位原码反码补码相同，所以=255
//	printf("a=%d b=%d c=%d", a, b, c);
//	return 0;
//}

//%d是打印十进制有符号数，原码反码补码不同
//%u是打印十进制无符号数，原码反码补码相同

//int main()
//{
//	char a = -128;
//	//10000000000000000000000010000000
//	//11111111111111111111111101111111
//	//11111111111111111111111110000000
//	//10000000
//	//11111111111111111111111110000000
//	printf("%u\n", a);//%u是打印十进制无符号数，补码就是原码，11111111111111111111111110000000=4294967168
//	return 0;
//}


//int main()
//{
//	int i = -20;
//	//10000000000000000000000000010100-原码
//	//11111111111111111111111111101011-反码
//	//11111111111111111111111111101100-补码
//	unsigned int j = 10;
//	//00000000000000000000000000001010-补码
//	printf("%d\n", i + j);
//	//11111111111111111111111111101100+
//	//00000000000000000000000000001010=
//	//11111111111111111111111111110110,%d按照十进制有符号位打印，原码反码补码不同
//	//11111111111111111111111111110101
//	//10000000000000000000000000001010=-10
//	return 0;
//}

//#include<Windows.h>
//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);//打印9，8，7，6，5，4，3，2，1，0然后无限循环，循环的原因是unsigned没有负数，i没有负数,0-1=255
//		Sleep(100);//用于停顿
//	}
//	return 0;
//}



//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;//a[0]=-1-0=-1,a[1]=-1-1=-2...a[1000]=-1-999=-1000
//	                  //但是有符号位的区间是-128~127，存不到-129...-1000 :-1,-2,-3...-126,-127,-128,127,126...2,1,0,-1,-2....
//	}
//	printf("%d", strlen(a));//打印字符串长度要找到\0,就是0，\0不算所以就是128+127=255
//	return 0;
//}

//unsigned char i = 0;
//int main()
//{
//	int count = 0;
//	for (i = 0; i <= 255; i++)//小于等于255会死循环，原因是在unsigned里255+1=0
//	{
//		count++;
//		printf("hellow\n");
//	}
//	printf("%d\n", count);
//	return 0;
//}


//整型和浮点型在内存中存储不同，整型是存的补码
//浮点数存的是根据国际标准IEEE（电气和电子工程协会）754，任意一个二进制浮点数可以表示成下面的方式：
//(-1)^S * M *2^E
//(-1)^S表示符号位，当S=0，V为正数；当S=1，V为负数
//M表示有效数字，大于等于一，小于二
//2^E表示指数位
//例子：flot a=9.0=
//1001.0  
//(-1)^0 * 1.001 * 2^3
//(-1)^S * M     * 2^E
//S=0,M=1.001,E=3
//E+127=130


//根据截图来看：
//float a=0.5=
//0.1,这个1是小数位，对于小数位来说是2的-1次方,写成科学的方式是(-1)^0 * 1.0 * 2^-1
//S=0,M=1.0,E=-1 ,但是E是不存符号位的，对于32位浮点数来说，E有8位,他的取值范围是0—255
//对于64位浮点数来说，E有11位,他的取值范围是0—2047
//所以E如果为负数，就要给他加上一个中间值,对于8位E加的是127，对于11位的E加的是1023 
//S=0
//M=1.0
//E=-1
//E+127=126,所以存的是126，但是E的真实值是E-127=-1
//E为正数也要加，统一一下


//int main()
//{
//	float a = 5.5;
//	//101.1
//	//(-1)^0 * 1.011 * 2^2
//	//S=0,M=1.011,E=2  .E计算机存的是129，10000001
//	//在内存中存储的是S，E，M
//	//0100 0000 1011 0000 0000 0000 0000 0000//1.011的前面的1不存进计算机，取出来时要加上，因为这个1是一定的，不存进计算机可以增加计算机的精确度
//	//0x40b00000
//	return 0;
//}

//从内存中拿出来有三种情况
//1. E不为全0或不为全1，用正常方法
//2. E为全0：这时，浮点数的E=1-127或者1-1023即为真实值，有效数字的M不再加上1，而是还原为0.xxxxxx的小数。这样做是为了表示+-0，以及接近0的很小的数字。
//3. E全为1：这时，如果有效数字全为0，表示+-无穷大（正负取决于符号位S）

//比如E全为0：0 00000000 01100000000000000000000
//S=0,E=1-127=-126,M=0.011
//(-1)^0 * 0.011 * 2^-126

//比如E全为1：0 11111111 01100000000000000000000
//S=0,E=255-127=128
//(-1)^0 * 1.xxxx * 2^128    ,S决定表示正负无穷大的数字


//int main()
//{
//	int n = 9;
//	//00000000000000000000000000001001--原反补相同
//	float* pFloat = (float*)&n;
//	printf("%d\n", n);//打印9
//	printf("%f\n", *pFloat);//0.000000
//	//0 00000000 00000000000000000001001
//	//(-1)^0 * 0.00000000000000000001001 * 2^-126  ,无限接近于0
//	*pFloat = 9.0;
//	//1001.0 ,S=0,E=3,M=1.001
//	//(-1)^0 * 1.001 * 2^130
//	//01000001000100000000000000000000
//	printf("%f\n", *pFloat);//9.000000
//	printf("%d\n", n);//1091567616
//	return 0;
//}


