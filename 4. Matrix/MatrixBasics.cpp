#include <bits/stdc++.h>
using namespace std;

class Matrix
{
    vector<vector<int>> arr;

public:
    void createMatrix(int r, int c)
    {
        arr.resize(r, vector<int>(c));
        cout << "\nInput Your Matrix: \n";
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << "\nMatrix Created Successfully!\n";
    }

    void displayMatrix()
    {
        if (arr.empty() || arr[0].empty())
        {
            cout << "Matrix is Empty!\n";
            return;
        }
        cout << "\nMatrix:\n";
        for (auto &row : arr)
        {
            for (auto &val : row)
                cout << val << " ";
            cout << endl;
        }
    }

    void searchElement(int s)
    {
        if (arr.empty() || arr[0].empty())
        {
            cout << "Matrix is Empty!\n";
            return;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                if (arr[i][j] == s)
                {
                    cout << "\nElement Found at: (" << i << ", " << j << ")\n";
                    return;
                }
            }
        }
        cout << "\nElement Not Found.\n";
    }

    void sortByRows()
    {
        for (auto &row : arr)
            sort(row.begin(), row.end());
        cout << "\nEach Row Sorted Successfully!\n";
    }

    void sortByColumns()
    {
        int r = arr.size(), c = arr[0].size();
        for (int col = 0; col < c; col++)
        {
            vector<int> temp;
            for (int row = 0; row < r; row++)
                temp.push_back(arr[row][col]);

            sort(temp.begin(), temp.end());

            for (int row = 0; row < r; row++)
                arr[row][col] = temp[row];
        }
        cout << "\nEach Column Sorted Successfully!\n";
    }

    void transposeMatrix()
    {
        int r = arr.size();
        int c = arr[0].size();
        vector<vector<int>> transposed(c, vector<int>(r));

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                transposed[j][i] = arr[i][j];

        arr = transposed;
        cout << "\nMatrix Transposed Successfully!\n";
    }

    void sumDiagonals()
    {
        int sumPrimary = 0, sumSecondary = 0;
        int n = arr.size();
        if (n == 0 || arr[0].size() != n)
        {
            cout << "\nDiagonal Sum only possible for Square Matrix!\n";
            return;
        }

        for (int i = 0; i < n; i++)
        {
            sumPrimary += arr[i][i];
            sumSecondary += arr[i][n - i - 1];
        }

        cout << "\nPrimary Diagonal Sum: " << sumPrimary;
        cout << "\nSecondary Diagonal Sum: " << sumSecondary << endl;
    }

    void multiplyWith(Matrix &m2)
    {
        int r1 = arr.size(), c1 = arr[0].size();
        int r2 = m2.arr.size(), c2 = m2.arr[0].size();

        if (c1 != r2)
        {
            cout << "\nMatrix Multiplication not possible!\n";
            return;
        }

        vector<vector<int>> result(r1, vector<int>(c2, 0));

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                for (int k = 0; k < c1; k++)
                {
                    result[i][j] += arr[i][k] * m2.arr[k][j];
                }
            }
        }

        cout << "\nResultant Matrix after Multiplication:\n";
        for (auto &row : result)
        {
            for (int val : row)
                cout << val << " ";
            cout << endl;
        }
    }
};

int main()
{
    Matrix m1, m2;
    int choice;

    do
    {
        cout << "\n======= Matrix Menu =======";
        cout << "\n1. Create Matrix";
        cout << "\n2. Display Matrix";
        cout << "\n3. Search Element";
        cout << "\n4. Sort by Rows";
        cout << "\n5. Sort by Columns";
        cout << "\n6. Transpose Matrix";
        cout << "\n7. Diagonal Sum";
        cout << "\n8. Multiply with Another Matrix";
        cout << "\n9. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int r, c;
            cout << "Enter rows and columns: ";
            cin >> r >> c;
            m1.createMatrix(r, c);
            break;
        }

        case 2:
            m1.displayMatrix();
            break;

        case 3:
        {
            int s;
            cout << "Enter element to search: ";
            cin >> s;
            m1.searchElement(s);
            break;
        }

        case 4:
            m1.sortByRows();
            break;

        case 5:
            m1.sortByColumns();
            break;

        case 6:
            m1.transposeMatrix();
            break;

        case 7:
            m1.sumDiagonals();
            break;

        case 8:
        {
            int r, c;
            cout << "Enter rows and columns for 2nd matrix: ";
            cin >> r >> c;
            m2.createMatrix(r, c);
            m1.multiplyWith(m2);
            break;
        }

        case 9:
            cout << "\nExiting...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 9);

    return 0;
}
