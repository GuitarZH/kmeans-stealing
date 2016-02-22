/**********************************************************************
* Nadesh Ramanathan, Imperial College London
*
* File: build_kdTree.h
*
* Additional Comments: distributed under a BSD license, see LICENSE.txt
*
**********************************************************************/


#ifndef BUILD_KDTREE_H
#define BUILD_KDTREE_H

#include "filtering_algorithm_util.h"
#include "stack.h"
#include "dyn_mem_alloc.h"

bool build_subtrees(uint p,
						uint n,
						node_pointer *root,
                        uint *size,
                        kdTree_type *image_r[P],
						data_type *initial_centre_positions,
						uint n0,
						uint k,
						double std_dev);

bool build_randomized_subtrees(uint p,
						uint n,
						node_pointer *root,
                        uint *size,
                        kdTree_type *image_r[P],
						data_type *initial_centre_positions,
						uint n0,
						uint k,
						double std_dev);

bool build_balanced_subtrees(uint p,
								uint n,
								node_pointer *root,
                                uint *size,
                                kdTree_type *image_r[P],
								data_type *initial_centre_positions,
								uint n0,
								uint k,
								double std_dev);

bool build_degenerate_subtrees(uint p,
								uint n,
								node_pointer *root,
                                uint *size,
                                kdTree_type *image_r[P],
								data_type *initial_centre_positions,
								uint n0,
								uint k,
								double std_dev);
/*
//file IO
bool read_data_points(uint n, uint k, double std_dev, data_type* points, uint* index);
bool read_initial_centres(uint n, uint k, double std_dev, data_type *initial_centre_positions, uint* centr_idx);
bool write_initial_centres(uint n, uint k, double std_dev, data_type *initial_centre_positions);


//tree build-up
void find_min_max(data_type* points, uint *idx, uint index, uint dim, uint n, coord_type *ret_min, coord_type *ret_max);
void compute_bounding_box(data_type* points, uint *idx, uint index, uint n, data_type *bnd_lo, data_type *bnd_hi);
void split_bounding_box(data_type* points, uint *idx, uint index, uint n, data_type *bnd_lo, data_type *bnd_hi, uint *n_lo, uint *cdim, coord_type *cval);
void setup_tree_node(uint idx, uint n, data_type bnd_lo, data_type bnd_hi, kdTree_ptr u);
node_pointer buildkdTreeFromDataSet(data_type* points, uint *idx, uint index, uint n, data_type *bnd_lo, data_type *bnd_hi, node_pointer root_offset, kdTree_type *heap);
void dot_product_tb(data_type_ext p1,data_type_ext p2, coord_type_ext *r);
void update_sums(node_pointer root, data_type* points, uint *idx, kdTree_type *heap);
void scale_sums(node_pointer root, kdTree_type *heap);
void readout_tree(bool write2file, uint n, uint k, double std_dev, node_pointer root, kdTree_type *heap, uint offset, uint partition, kdTree_ptr image, node_pointer *image_addr);

void make_data_points_file_name_perfect(char *result, uint n, uint k, uint d, bool hex);
void make_initial_centres_file_name_perfect(char *result, uint n, uint k, uint d, uint index, bool hex);
*/


//helper macros
/*
#define get_coord(points, indx, idx, dim) ( get_coord_type_vector_item((points+*(indx+idx))->value,dim) )
#define coord_swap(indx, i1, i2) { uint tmp = *(indx+i1);\
                                    *(indx+i1) = *(indx+i2);\
                                    *(indx+i2) = tmp; }
*/

#define get_coord(points, indx, idx, dim) ( get_coord_type_vector_item(points[*(indx+idx)].value,dim) )
#define coord_swap(indxarr,idx,i1, i2) {uint tmp = indxarr[idx+i1];\
                                        indxarr[idx+i1] = indxarr[idx+i2];\
                                        indxarr[idx+i2] = tmp; }



#endif  /* BUILD_KDTREE_H */
