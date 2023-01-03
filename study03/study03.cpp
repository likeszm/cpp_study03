/*
* 名称：修饰符类型和存储类
* 
* 修饰符类型：long 和 short 、 unsigned 和 signed 
* 限定符：  const、restrict、volatile
* 存储类：  auto、register、static、extern、mutable、thread_local
* 
* 额外收获：用wcout方法替代cout，兼容Unicode编码
 */

/*
* 类型限定符说明
* 
* const :   常量标识符
* restrict :限定这个变量如果想要修改只能通过指针的方式。 
* volatile :取消优化。因为一般的变量会取到寄存器内操作，可以优化速度。
加了这个关键字就不会取到寄存器内，而是直接在内存中操作。 
* 
*/

/*
* 存储类说明:
* auto : 自动存储类，不用管
* register : 修饰的变量将会尽量存放在寄存器内，所以不在内存里面，就不能用&取地址
* static :  对于局部变量，延长生命周期，不会一次又一次的创建和销毁，变量值也会一直记住
*           对于全局变量，限制作用域不能到其他文件
*           如果用在类成员变量，这个变量将会是所有的成员共享的
* extern :  用于说明外部文件已经定义了某个函数或者变量。
* mutable:  它允许对象的成员替代常量。也就是说，mutable 成员可以通过 const 成员函数修改
* thread_local :    使用 thread_local 说明符声明的变量仅可在它在其上创建的线程上访问。
*                   变量在创建线程时创建，并在销毁线程时销毁。 每个线程都有其自己的变量副本。
* 
*/

#include <iostream>


//#error 这是一条错误     //手动报错

//#define STATIC_TEST 1
/*不想测试请注释宏定义
* 1：测试对局部变量的修饰
* 2：测试本文件读取外部文件变量
* 3：测试外部文件读取本文件变量
*/

#ifdef STATIC_TEST

#if (STATIC_TEST == 1)

int local_variable_test(void);

#elif (STATIC_TEST == 2)

#include "test.cpp"
extern int test_global_variable;

#elif (STATIC_TEST == 3)

//#include "test.cpp"
extern int my_read_main_variable(void);

#if 0         //输入0则不测试static ， 输入1测试结果为报错
static int main_global_variable = 0;
#else 
int main_global_variable = 0;
#endif

#else 
#error "STATIC_TEST" 宏定义值非法!
#endif 

#endif // STATIC_TEST


int main()
{


#ifdef STATIC_TEST

#if (STATIC_TEST == 1)

    for (int i = 1; i < 10; i++)
    {
        std::cout << "第" << i << "次调用函数" << std::endl;
        std::cout << "局部变量值为：" << local_variable_test()
            << std::endl << std::endl;
    }

#elif (STATIC_TEST == 2)

    std::cout << "尝试读取外部文件的变量值：" << std::endl
        << "test_global_variable = " << test_global_variable << std::endl;

#elif (STATIC_TEST == 3)
   
    for (int i = 1; i < 10; i++)
    {
        std::cout << "第" << i << "次调用函数" << std::endl;
        std::cout << "局部变量值为："   << my_read_main_variable()
            << std::endl << std::endl;
    }
#else 
#error "STATIC_TEST" 宏定义值非法!
#endif 

#endif // STATIC_TEST



    std::cout << "\n测试完成\n";
    
    return 0;
}

#ifdef STATIC_TEST

#if (STATIC_TEST == 1)

int local_variable_test(void)
{
    static int test_local_variable = 0;
    test_local_variable++;
    return test_local_variable;
}


#elif (STATIC_TEST == 2)

#elif (STATIC_TEST == 3)

#else 
#error "STATIC_TEST" 宏定义值非法!
#endif 

#endif // STATIC_TEST
