#include<stdio.h>

int main()
{
    long int a, i, b, d; //a�O�p���ܼ�(���ƪ�)�Fi�O�ĴX��Ƥ��ܼơFb�O�p���ܼ�(��X��)�Fd�O���-1�A�Y�}�C���̤j��
    long long int n, m, v, s; //n�O���ơFm�O���ơFv�O�i��Ȧs�ܼơFs�ΨӰO����Ʀ��
    while(1)
    {
        printf("�п�J�G���n,m�A���{���N�p��n^m: ");
        scanf("%lld%lld", &n, &m);
        long long int x[100000] = {0}; //�ŧiint x�}�C
        v = 0; //�M��v����
        s = 1; //���ޫ��ˡAs���|�j�󵥩�1�A�]����Ƥ@�w�����
        x[0] = 1; //�����̦��n�����o��}�C�ȵ���1
        for(a = 1; a <= m; a++)
        {
            for(i=0;i<s;i++)
            {
                x[i] = x[i] * n + v; //�U�Ӧ�ƹB�⦡�Av�O���i��ɭn�[�W�h��
                v = x[i] / 1000000000; //v�Y�j��0�A�h�ݶi��
                x[i] = x[i] % 1000000000; //�C��}�C�s�E���
                if(v != 0 && i + 1 == s) //�P�_�}�C�O�_+1
                s++; //�O���}�C���
            }
        }

        printf("�ȡG");
        for(b = s - 1; b >= 0; b--) //�ϦV��X
        {
            if(b != s - 1) //�̫e�����}�C�e�������0
            //cout << setfill('0') << setw(9) << x[b];
                printf("%d", x[b]);
            else //�̫e�����}�C��X
                printf("%d", x[b]);
        }
        putchar('\n'); //����

        if(i == 1) //�p�G��Ƥ��W�L�@�Ӱ}�C(�Y���W�L9���)
        {
            s = 0; //�}�C��ƲM��
            while(x[0] >= 1) //���o��Ʀ��
            {
                x[0] = x[0] / 10;  //�h���̫�@��
                s++;  //��Ʀ�ƥ[�@
            }
        }
        else //�p�G��ƶW�L�@�Ӱ}�C(�Y�W�L9���)
        {
            d = s - 1; //d�O�}�C�̤j��
            s = (s - 1) * 9; //�}�C��Ʀ����̫e�����}�C�A��9�A�N�O�����̫e�����}�C�ثe����Ʀ��
            while(x[d] >= 1) //���o��Ʀ��
            {
                x[d] = x[d] / 10; //�h���̫�@��
                s++; //��Ʀ�ƥ[�@
            }
        }
        printf("�@%d�Ӧ��\n", s);
    }

    return 0;
}
