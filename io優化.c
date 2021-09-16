#include <stdio.h>
#define SIZE 131072
#define BUFSIZE 1048576//<- 2**n
//2097152

// readint

static inline int get_int(register int *n){
    register char tc ;
    int si = 1;
    while((tc = getchar()) < '0' && tc != '-')
        if(tc == EOF)return 0;
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    *n = tc ^ '0';
    while((tc = getchar()) >= '0')
        *n = (*n << 1) + (*n << 3) + (tc ^ '0');
    *n *= si;
    return 1;
}

static inline int get_LLint(register long long int *n){
    register char ch ;
    while((ch = getchar()) < '-')
        if(ch == EOF)return 0;
    if(ch == '-'){
        *n = getchar() ^ '0';
        while((ch = getchar()) >= '0')
            *n = (*n << 1) + (*n << 3) + (ch ^ '0');
        *n = ~*n + 1;
    }
    else {
        *n = ch ^ '0';
        while((ch = getchar()) >= '0')
            *n = (*n << 1) + (*n << 3) + (ch ^ '0');
    }
    return 1;
}

/*static inline int get_int(){
    int n = 0, si = 1;
    register char tc = getchar();
    while(tc < '0' && tc != '-')tc = getchar();
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    while(tc >= '0'){
        n = (n << 1) + (n << 3) + (tc ^ '0');
        tc = getchar();
    }
    return n * si;
}*/

static inline char readChar(){
    static char buf[BUFSIZE], *temp = buf + BUFSIZE, *end = buf + BUFSIZE;
    if(temp == end){
        if(end < buf + BUFSIZE)
            return EOF;
        end = buf + fread(buf, 1, BUFSIZE, stdin);
        temp = buf;
    }
    return *temp++;
}

static inline char readint(register int *input){
    register char ch;
    int flag = 1;
    while((ch = readChar()) < '0' && ch != '-')
        if(ch == EOF) return 0;
    if(ch == '-'){
        ch = readChar();
        flag = -1;
    }
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    *input *= flag;
    return 1;
}

// unsinged

static inline char readUint(register unsigned int *input){
    register char ch;
    while((ch = readChar()) < '0')
        if(ch == EOF) return 0;
    *input = ch ^ '0';
    while((ch = readChar()) >= '0')
        *input = (*input << 3) + (*input << 1) + (ch ^ '0');
    return 1;
}

// putint

static inline void putint(register int output){
    if(output == 0)putchar('0');
    char buf[13];
    char *p = buf + 11;
    *(p + 1) = '\0';
    if(output < 0){
        putchar('-');
        output = ~output + 1;
    }
    while(output){
        *p-- = '0' ^ (output % 10);
        output /= 10;
    }
    fputs(++p, stdout);
    putchar('\n');
}

/*static inline void putint(int output){
    int size = 0;
    char buf[13];
    if(output < 0){
        putchar('-');
        output *= -1;
    }
    while(output){
        buf[size++] = '0' ^ (output % 10);
        output /= 10;
    }
    for(size--; size > -1; size--)putchar(buf[size]);
    //putchar('');
}*/

static inline void putUInt(register unsigned int src, const char suffix){
    static char tmp[13];
    register unsigned int div;
    char* st = tmp + 11;
    *st = suffix, * (st + 1) = '\0';
    do
    {
        *(--st) = (src - ((div = src / 10) << 3) - (div << 1)) | '0';
    } while (src = div);
    fputs(st, stdout);
}

inline void putInt(register int src, const char suffix)
{
    static char tmp[13];
    register unsigned int div;
    char* st = tmp + 11;
    *st = suffix, * (st + 1) = '\0';
    if (src < 0)
    {
        src = ~src + 1;
        *(--st) = (src - ((div = src / 10) << 3) - (div << 1)) | '0';
        while (src = div)
            * (--st) = (src - ((div = src / 10) << 3) - (div << 1)) | '0';
        *(--st) = '-';
    }
    else
    {
        do
        {
            *(--st) = (src - ((div = src / 10) << 3) - (div << 1)) | '0';
        } while (src = div);
    }
    fputs(st, stdout);
}

char out[SIZE];// put int -> string
int count = 0;

void appendInt(int temp){
    int index = 0;
    char num[13];
    while(temp){
        num[index++] = '0' ^ (temp % 10);
        temp /= 10;
    }
    for(temp = count, count += index--; temp < count; temp++, index--)
        out[temp] = num[index];
}


////

void main(){



}

// input uint



//llint

/*long long int get_llint(){
  long long int n=0,si=1; char tc=getchar();
  while((tc<'0'||tc>'9')&&tc!='-') tc=getchar();
  if(tc=='-') tc=getchar(),si=-1;
  while(tc>='0'&&tc<='9') n=n*10+(tc-'0'),tc=getchar();
  return n*si;
}

void putllint(long long int out)
{
  char buf[1000];
  int n=0;
  if(out<0) putchar('-'),out=out*-1;
  do
  {
    buf[n++]='0'+(out%10);
    out=out/10;
  }while(out>0);
  for(n=n-1;n>=0;n--)
    putchar(buf[n]);
  putchar('\n');  //視情況加入
}


//int

void putint(int out){
    char buf[1000];
    int n = 0;
    if(out < 0){
        putchar('-');
        out *= -1;
    }
    do
    {
        buf[n++] = '0' + (out%10);
        out /= 10;
    }while(out > 0);
    for(--n; n >= 0; --n)putchar(buf[n]);
    //putchar(' ');
}

int get_int(){
    int n = 0, si = 1;
    char tc = getchar();
    while((tc<'0'||tc>'9') &&  tc != '-')tc = getchar();
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    while(tc >= '0' && tc <= '9'){
        n = (n<<1) + (n<<3) + (tc ^ '0');
        tc = getchar();
    }
    return n * si;
}


#define BUFSIZ 1048576

inline char readChar()
{
    static char buffer[BUFSIZ], * t0 = buffer + BUFSIZ, * end = buffer + BUFSIZ;
    if (t0 == end)
    {
        if (end < buffer + BUFSIZ)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZ, stdin));
        t0 = buffer;
    }
    return *t0++;
}

inline char readUInt(unsigned int* dst)
{
    register char ch;
    while ((ch = readChar()) < '0')
        if (ch == EOF) return 0;
    *dst = ch ^ '0';
    while ((ch = readChar()) >= '0')
        * dst = (*dst << 3) + (*dst << 1) + (ch ^ '0');
    return 1;
}

//ex

int main()
{
    unsigned int n, ans = 0, tmp;
    scanf(" %d", &n);
    while (--n)
    {
        readUInt(&tmp);
        ans ^= tmp;
    }
    printf("%d", ans);
    return 0;
}


void putint(int out){
    char buf[1000];
    int n = 0;
    if(out < 0){
        putchar('-');
        out *= -1;
    }
    do
    {
        buf[n++] = '0' + (out%10);
        out /= 10;
    }while(out > 0);
    for(--n; n >= 0; --n)putchar(buf[n]);
    //putchar(' ');
}

int get_int(){
    int n = 0, si = 1;
    char tc = getchar();
    while((tc<'0'||tc>'9') &&  tc != '-')tc = getchar();
    if(tc == '-'){
        tc = getchar();
        si = -1;
    }
    while(tc >= '0' && tc <= '9'){
        n = (n<<1) + (n<<3) + (tc ^ '0');
        tc = getchar();
    }
    return n * si;
}*/
