## static关键字

#### static局部变量

static局部变量在当前文件等同于全局变量

static局部变量只能在当前文件访问，其他文件不能通过extern访问

#### static类

static对象的构造在main函数前执行，析构在main函数结束后

#### static成员变量

存在于所有对象且保持一致，可在其他文件访问

不能在初始化列表初始化

需在类外定义，因为class内语句都是声明

#### static成员函数

可通过类名::函数调用，只能使用static成员变量，否则报错，没有this指针，不能访问非static成员 变量。