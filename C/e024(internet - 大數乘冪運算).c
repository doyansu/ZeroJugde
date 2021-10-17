#include<stdio.h>

int main()
{
    long int a, i, b, d; //a琌璸Ω跑计(计)i琌材碭计ぇ跑计b琌璸Ω跑计(块)d琌计-1皚程
    long long int n, m, v, s; //n琌┏计m琌计v琌秈既跑计sノㄓ癘魁俱计计
    while(1)
    {
        printf("叫块俱计n,mセ祘Α盢璸衡n^m: ");
        scanf("%lld%lld", &n, &m);
        long long int x[100000] = {0}; //int x皚
        v = 0; //睲v
        s = 1; //ぃ恨或妓sゲ穦单1俱计﹚Τ计
        x[0] = 1; //琵程Ν璶硂皚单1
        for(a = 1; a <= m; a++)
        {
            for(i=0;i<s;i++)
            {
                x[i] = x[i] * n + v; //计笲衡Αv琌Τ秈璶
                v = x[i] / 1000000000; //v璝0玥惠秈
                x[i] = x[i] % 1000000000; //–皚计
                if(v != 0 && i + 1 == s) //耞皚琌+1
                s++; //癘魁皚计
            }
        }

        printf("");
        for(b = s - 1; b >= 0; b--) //は块
        {
            if(b != s - 1) //程玡皚玡ぃ干0
            //cout << setfill('0') << setw(9) << x[b];
                printf("%d", x[b]);
            else //程玡皚块
                printf("%d", x[b]);
        }
        putchar('\n'); //传︽

        if(i == 1) //狦俱计ぃ禬筁皚(ぃ禬筁9计)
        {
            s = 0; //皚计睲埃
            while(x[0] >= 1) //眔俱计计
            {
                x[0] = x[0] / 10;  //奔程
                s++;  //俱计计
            }
        }
        else //狦俱计禬筁皚(禬筁9计)
        {
            d = s - 1; //d琌皚程
            s = (s - 1) * 9; //皚计Ι奔程玡皚9碞琌Ι奔程玡皚ヘ玡俱计计
            while(x[d] >= 1) //眔俱计计
            {
                x[d] = x[d] / 10; //奔程
                s++; //俱计计
            }
        }
        printf("%d计\n", s);
    }

    return 0;
}
