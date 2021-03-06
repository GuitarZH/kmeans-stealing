/**********************************************************************
 * Nadesh Ramanathan, Imperial College London
 *
 * File: dyn_mem_alloc.h
 *
 * Additional Comments: distributed under a BSD license, see LICENSE.txt
 *
 **********************************************************************/


#ifndef _DYN_MEM_ALLOC_H_
#define _DYN_MEM_ALLOC_H_

#define NULL_PTR 0



    template <class address_type>
address_type malloc(address_type* flist, address_type* next_free_location)
{
    address_type address = *next_free_location;
    *next_free_location = flist[(uint)address];

    return address;
}

    template <class address_type>
void free(address_type* flist, address_type* next_free_location, address_type address)
{
    flist[(uint)address] = *next_free_location;
    *next_free_location = address;
}

    template <class address_type>
void init_allocator(address_type* flist, address_type* next_free_location, const address_type heapsize)
{
init_allocator_loop: for (address_type i=0; i<=heapsize; i++) {
                         flist[(uint)i] = i+1;
                         if (i==heapsize) {
                             break;
                         }
                     }
                     *next_free_location = 1;
}


    template <class data_type>
data_type* make_pointer(data_type* mem, unsigned int offset) // offset must be int here (not address_type)
{
    return (mem+offset); //return pointer
}


    template <class data_type>
volatile data_type* make_pointer(volatile data_type* mem, unsigned int offset) // offset must be int here (not address_type)
{
    return (mem+offset); //return pointer
}


    template <class address_type, class data_type>
void readout_heapimage(data_type* mem, data_type* image, const uint heapsize)
{
    for (uint i=0; i<=heapsize; i++) {
        data_type tmp = mem[i];
        image[i] = tmp;
        if (i==heapsize) {
            break;
        }
    }
}

#endif
