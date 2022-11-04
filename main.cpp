//Wienczyslaw Wlodyga
#include <iostream>
using namespace std;
// VARIABLES
unsigned int sessions;
int elementIndex, length, invLength, shiftLength, switchLength, shiftpos, sortLength;
char operation;
// MAIN
int main() {
    cin >> sessions;
    int i = 0;
    while (i < sessions) {
        cin >> length;
        int tab[length];
        int j = 0;
        while (j < length) {
            cin >> tab[j];
            j++;
        }
        j = 0;
        while (j < length) {
            cout << tab[j] << " ";
            j++;
        }

        cout << endl;
        do {
            cin >> operation;

            //INV
            if(operation=='R'){
                cin >> elementIndex >> invLength;
                int b = 0;
                while (b < (length / invLength)) {
                    while(elementIndex<0)elementIndex=length-(-elementIndex);
                    if (elementIndex != length) elementIndex = elementIndex % length;
                    else elementIndex = 0;
                    int flIndex = elementIndex + invLength - 1;
                    if (flIndex<0) flIndex=length-(-flIndex);
                    if (flIndex != length) flIndex = flIndex % length;
                    else flIndex = 0;
                    int k = elementIndex;
                    int n = flIndex;
                    int m = 0;
                    while (m < (invLength / 2)) {
                        while (n < 0) n = length - (-n);
                        while (k < 0) k = length - (-k);
                        if (k != length) k = k % length;
                        else k = 0;
                        if (n != length) n = n % length;
                        else n = 0;
                        swap(tab[k], tab[n]);
                        k++;
                        n--;
                        m++;
                        if (n < 0) n = length - (-n);
                    }
                    b++;
                    elementIndex = elementIndex + invLength;

                }
            }
            //SHIFT
            if(operation=='M')
            {
                cin >> elementIndex >> shiftLength >> shiftpos;
                //SHIFT+
                if (shiftpos > 0) {
                    int LdSL=length/shiftLength;
                    int c = 0;
                    while (c <= LdSL) {
                        while (elementIndex < 0) elementIndex = length - (-elementIndex);
                        if (elementIndex != length) elementIndex = elementIndex % length;
                        else elementIndex = 0;
                        int slIndex = elementIndex + shiftLength - 1;
                        if (slIndex != length) slIndex = slIndex % length;
                        else slIndex = 0;
                        int x = elementIndex;
                        int y = slIndex;
                        int z = shiftpos;
                        while (z > 0) {
                            int temp = tab[y];
                            int g = y;
                            int u = y - 1;
                            while (g != x) {
                                if (g < 0)g = length - (-g);
                                if (u < 0)u = length - (-u);
                                tab[g] = tab[u];
                                g--;
                                u--;
                            }
                            tab[x] = temp;
                            z--;
                        }
                        c++;
                        if(c==LdSL&&(length%shiftLength==0)){
                            c=c+1;
                        }
                        if(c==LdSL){
                            shiftLength=length%shiftLength;
                            elementIndex=slIndex+1;
                        }
                        else elementIndex = elementIndex + shiftLength;
                    }
                }
                //SHIFT-

                if (shiftpos < 0) {
                    int LdSL=length/shiftLength;
                    int c = 0;
                    while (c <= LdSL) {
                        while (elementIndex < 0) elementIndex = length - (-elementIndex);
                        if (elementIndex != length) elementIndex = elementIndex % length;
                        else elementIndex = 0;
                        int slIndex = elementIndex + shiftLength - 1;
                        if (slIndex != length) slIndex = slIndex % length;
                        else slIndex = 0;
                        int x = elementIndex;
                        int y = slIndex;
                        int z = shiftpos;
                        while (z < 0) {
                            int temp = tab[x];
                            int g = x;
                            int u = x+1;
                            while (g != y) {
                                if (g >= length) tab[g]=tab[g-length];
                                if (u >= length)u = 0+(-(length-u));
                                if (g >= length)g = 0+(-(length-g));
                                tab[g]=tab[u];
                                g++;
                                if (g >= length)g = 0+(-(length-g));
                                u++;
                            }
                            tab[y] = temp;
                            z++;
                        }
                        c++;
                        if(c==LdSL&&(length%shiftLength==0)){
                            c=c+1;
                        }
                        if(c==LdSL){
                            shiftLength=length%shiftLength;
                            elementIndex=slIndex+1;
                        }
                        else elementIndex = elementIndex + shiftLength;
                    }
                }
            }

            //SWITCHING PAIRS
            if (operation=='C'){
                cin >> elementIndex >> switchLength;
                int r=0;
                int swFragments=length/switchLength;
                while (r<(swFragments/2)) {
                    while (elementIndex<0)elementIndex=0+(length-(-elementIndex));
                    while (elementIndex>=length)elementIndex=0+(-(length-elementIndex));
                    if (elementIndex != length) elementIndex = elementIndex % length;
                    else elementIndex = 0;
                    int q = elementIndex;
                    int e = 0;
                    int w = q + switchLength;
                    while (e < switchLength) {
                        if (q != length) q = q % length;
                        else q = 0;
                        if (w != length) w = w % length;
                        else w = 0;
                        swap(tab[q], tab[w]);
                        q++;
                        w++;
                        e++;
                    }
                    r++;
                    elementIndex = elementIndex + 2 * switchLength;
                }
            }
            //SORT
            if(operation=='S'){
                //SORT (LOWEST TO HIGHEST)
                cin >> elementIndex >> sortLength;
                int tempLH = sortLength;
                int LdSWL = length / sortLength;
                if (sortLength > 0) {
                    int c = 0;
                    while (c <= LdSWL) {
                        int d = 0, f = 0;
                        while (d < sortLength - 1) {
                            int x = elementIndex;
                            int y = elementIndex + 1;
                            while (f < sortLength - 1) {
                                while (x >= length)x = 0 + (-(length - x));
                                while (x < 0)x = 0 + (length - (-x));
                                if (x != length)x = x % length;
                                while (y >= length) y = 0 + (-(length - y));
                                while (y < 0)y = 0 + (length - (-y));
                                if (y != length)y = y % length;
                                if (tab[x] > tab[y])swap(tab[x], tab[y]);
                                x++;
                                y++;
                                f++;
                            }
                            d++;
                            f = 0;

                        }

                        c++;
                        if (c == LdSWL && (length % sortLength == 0)) {
                            c = c + 1;
                        }

                        if (c == LdSWL) {
                            sortLength = length % sortLength;
                            elementIndex = elementIndex + tempLH;
                        }
                        else  elementIndex = elementIndex + sortLength;
                    }

                }
                //SORT (HIGHEST TO LOWEST)
                int tempHL = (-sortLength);
                if (sortLength < 0) {
                    int c = 0;
                    while (c >= LdSWL) {
                        int d = 0, f = 0;
                        while (d < tempHL -1 ) {
                            int x = elementIndex;
                            int y = elementIndex + 1;
                            while (f < tempHL -1 ) {
                                while(x >= length)x = 0 + (-(length - x));
                                while (x < 0)x = 0 + (length - (-x));
                                if (x != length)x = x % length;
                                while (y >= length) y = 0 + (-(length - y));
                                while (y < 0)y = 0 + (length - (-y));
                                if (y != length)y = y % length;
                                if (tab[x] < tab[y])swap(tab[x], tab[y]);
                                x++;
                                y++;
                                f++;
                            }
                            d++;
                            f = 0;

                        }

                        c--;
                        if (c == LdSWL && (length % tempHL == 0)) {
                            c = c - 1;
                        }

                        if (c == LdSWL) {

                            elementIndex = elementIndex + tempHL;
                            tempHL=length%(-(sortLength));
                        }
                        else elementIndex = elementIndex + tempHL;

                    }

                }
            }
        }

        while(operation!='F');
        j = 0;
        while (j < length) {
            cout << tab[j] << " ";
            j++;
        }
        i++;
        if(i<sessions)cout<<endl;
    }


    return 0;

}