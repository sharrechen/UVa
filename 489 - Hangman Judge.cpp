#include <cstdio>
#include <cstring>

using namespace std;

int main(void) {

	int round, strokes, answer, correct, len, alphabet[32]={0};
	char input[128];

	while (scanf("%d\n", &round), ~round) {
		answer = correct = strokes = 0;
		
		// get answer
		gets(input);
		len = strlen(input);
		for (int i = 0; i < len; i++) {
			if (alphabet[input[i] - 'a'] == 0) {
				alphabet[input[i] - 'a'] = 1;
				answer++;
			}
		}

		// get guess
		gets(input);
		len = strlen(input);
		for (int i = 0; strokes < 7 && i < len; i++) {
			if (alphabet[input[i] - 'a'] == 0) {
				alphabet[input[i] - 'a'] = -1;
				strokes++;
			} else if (alphabet[input[i] - 'a'] == 1) {
				alphabet[input[i] - 'a'] = -1;
				correct++;
			}
		}
		
		printf("Round %d\n", round);
		if (correct == answer) printf("You win.\n");
		else if (strokes >= 7) printf("You lose.\n");
		else printf("You chickened out.\n");
		memset(alphabet, 0, sizeof(alphabet));
	}

	return 0;
}
