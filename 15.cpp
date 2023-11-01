//15. Sparse matrix representation and operations 
#include <iostream>
#include <vector>

using namespace std;
class Element {
public:
    int row, col, value;
    Element(int r, int c, int v) : row(r), col(c), value(v) {}
};

class SparseMatrix {
private:
    int rows, cols;
    vector<Element> elements;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}
    void inputSparseMatrix() {
        cout << "Enter the number of non-zero elements: ";
        int numNonZero;
        cin >> numNonZero;
        elements.clear();
        elements.reserve(numNonZero);
        cout << "Enter non-zero elements (row, column, value):" << endl;
        for (int i = 0; i < numNonZero; ++i) {
            int row, col, value;
            cin >> row >> col >> value;
            elements.emplace_back(row, col, value);
        }
    }
    void printSparseMatrix() const {
        cout << "Sparse Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                bool found = false;
                for (const Element &elem : elements) {
                    if (elem.row == i && elem.col == j) {
                        cout << elem.value << " ";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    void addElement(int row, int col, int value) {
        elements.push_back(Element(row, col, value));
    }
    friend SparseMatrix addMatrices(const SparseMatrix& mat1, const SparseMatrix& mat2) ;
};
SparseMatrix addMatrices(const SparseMatrix& mat1, const SparseMatrix& mat2) {
    SparseMatrix result(mat1.rows, mat1.cols);
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        cout << "Matrix dimensions do not match for addition." << endl;
        return result;    
    }


    for (int i=0;i < mat1.elements.size();i++) {
        const Element& elem1 = mat1.elements[i];
        result.addElement(elem1.row, elem1.col, elem1.value);
    }
    for (int i=0;i < mat1.elements.size();i++) {
        const Element& elem2 = mat2.elements[i];
        bool found=false;
        for (int j=0;j < result.elements.size();j++) {
            if(result.elements[j].row==elem2.row&&result.elements[j].col==elem2.col){
                found=true;
                result.elements[j].value+=elem2.value;
                break;
            }
        }
        if(!found){
            result.addElement(elem2.row, elem2.col, elem2.value);
        }
    }

    return result;
}
int main() {
    cout << "Enter details for the first sparse matrix:" << endl;
    int rows1, cols1;
    cout << "Enter the number of rows and columns: ";
    cin >> rows1 >> cols1;
    SparseMatrix matrix1(rows1, cols1);
    matrix1.inputSparseMatrix();

    cout << "\nEnter details for the second sparse matrix:" << endl;
    int rows2, cols2;
    cout << "Enter the number of rows and columns: ";
    cin >> rows2 >> cols2;
    SparseMatrix matrix2(rows2, cols2);
    matrix2.inputSparseMatrix();

    cout << "\nSparse Matrix 1:" << endl;
    matrix1.printSparseMatrix();

    cout << "\nSparse Matrix 2:" << endl;
    matrix2.printSparseMatrix();

    SparseMatrix result = addMatrices(matrix1,matrix2);

    cout << "\nResultant Sparse Matrix (Sum of Matrix 1 and Matrix 2):" << endl;
    result.printSparseMatrix();

    return 0;
}