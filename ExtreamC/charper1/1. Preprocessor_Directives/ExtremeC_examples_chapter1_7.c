// To define CONDITION macro
// use -DCONDITION option when using gcc
// #define CONDITION

int main(int argc, char** argv) {
#ifdef CONDITION
	int i = 0;
	i++;
#endif
	int j = 0
	return 0;
}
