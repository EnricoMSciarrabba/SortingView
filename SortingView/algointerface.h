#ifndef ALGOINTERFACE_H
#define ALGOINTERFACE_H

#include <vector>

class AlgoInterface
{
public:
    AlgoInterface();
    virtual ~AlgoInterface(){};

    void setData(std::vector<int> data);

    // Metodo per il sort
    virtual void sort() = 0;

protected:
    std::vector<int> m_data;
};

#endif // ALGOINTERFACE_H
