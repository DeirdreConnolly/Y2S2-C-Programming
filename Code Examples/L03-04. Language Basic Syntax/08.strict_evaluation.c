
/*
- Does this program hang?
*/

int loop() {
	return loop();
}

int second(int a, int b) {
	return b;
}

int main() {
	int val = second(loop(), 3);

	return val;
}

