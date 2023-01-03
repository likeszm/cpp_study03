#ifndef TEST_H
#define TEST_H

static int test_global_variable = 1112;

extern int main_global_variable;

int my_read_main_variable(void)
{
	++main_global_variable;
	return main_global_variable;
}

#endif // !TEST_H

