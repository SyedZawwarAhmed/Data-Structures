class MultidimensionalArray {
    int noOfDimensions;
    int* sizesOfDimensions;
    int* data;
    public:
    MultidimensionalArray(int noOfDimensions, int sizesOfDimensions[]);
    int getAddress(int indices[]);
    int getItem(int indices[]);
    void setItem(int item, int indices[]);
};