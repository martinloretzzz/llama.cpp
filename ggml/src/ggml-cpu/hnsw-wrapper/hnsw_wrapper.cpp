extern "C"
{
#include "hnsw_wrapper.h"
}

#include "hnswlib/hnswlib.h"

void search_load_index(const float *query, float *dest, int k, int dimensions, int ef)
{
    static hnswlib::HierarchicalNSW<float> *index = nullptr;
    static hnswlib::InnerProductSpace *     space        = nullptr;

    if (index == nullptr)
    {
        std::string hnsw_path = "./hnsw.index";
        space        = new hnswlib::InnerProductSpace(dimensions);
        index = new hnswlib::HierarchicalNSW<float>(space, hnsw_path);
        index->setEf(ef);
    }

    std::priority_queue<std::pair<float, hnswlib::labeltype>> result = index->searchKnn(query, k);

    for (int i = 0; i < k; ++i)
    {
        int id = result.top().second;
        float distance = 1 - result.top().first;
        dest[id]       = distance;

        if (!result.empty()) {
            result.pop();
        }
    }
}
