int main(void) {
char fruit[] = "apple";
  char ans[80];
  do {
     printf ("Guess my favorite fruit? ");
     scanf ("%s",ans);
  } while (strcmp (fruit, ans) != 0);
  puts ("Correct answer!");
  return 0;
}
