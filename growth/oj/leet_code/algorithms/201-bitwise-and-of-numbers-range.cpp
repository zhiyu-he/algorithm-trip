#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0) return 0;
        int m_bit_size = 0;
        int m1 = m;
        while(m1) {
            m_bit_size += 1;
            m1 = m1 >> 1;
        }

        int n_bit_size = 0;
        int n1 = n;
        while(n1) {
            n_bit_size += 1;
            n1 = n1 >> 1;
        }
        if (n_bit_size > m_bit_size) return 0;
        while(m_bit_size) {
            bool is_one1 = m >> (m_bit_size-1) & 1;
            bool is_one2 = n >> (m_bit_size-1) & 1;
            if (is_one1 == true && is_one1 == is_one2) {
                int tmp = n - (1 << (m_bit_size -1));
                if (tmp >= m)
                    break;
            }
            cout << "m_bit_size " << m_bit_size << " f " << is_one1 << " f2 " << is_one2 << endl;
            if (is_one2 == true && is_one2 != is_one1)
                break;
            if (is_one1 != is_one2)
                m &= ~(1 << (m_bit_size -1));
            m_bit_size--;
        }
        //cout << "m : " << m << "  bit_size " << m_bit_size << endl;
        while(m_bit_size) {
            m &= ~(1 << (m_bit_size -1));
            m_bit_size--;
        }
        
        return m;
    }
};

int main() {
    Solution s;
    /*
    cout << s.rangeBitwiseAnd(5, 7) << endl;
    cout << s.rangeBitwiseAnd(1, 2147483647) << endl;
    cout << s.rangeBitwiseAnd(1, 1) << endl;
    cout << s.rangeBitwiseAnd(1, 1) << endl;
    cout << s.rangeBitwiseAnd(600000000,2147483645) << endl;
    cout << s.rangeBitwiseAnd(9, 10) << endl;
    */
    cout << s.rangeBitwiseAnd(11, 12) << endl;






    return 0;
}
