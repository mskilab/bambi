#include <inttypes.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> // for optparse
#include <Rcpp.h>
#include <iostream>
#include <stdio.h>

#include "htslib/hts.h"
#include "htslib/bgzf.h"
#include "htslib/hts.h"

#include "include/bamdb.h"
#include "include/bam_lmdb.h"
#include "include/bam_api.h"
#include "include/bamdb_c.h"

using namespace Rcpp;
using namespace std;

/* Command to do successfully run.
barcodedReads('/gpfs/commons/groups/imielinski_lab/data/10X/bam3/HCC1143_BL_phased_possorted.bam','/gpfs/commons/groups/imielinski_lab/data/10X/bam3/HCC1143_BL_phased_possorted.db','GTGGTCGCAACGCTTA-1')
*/

#define WORK_BUFFER_SIZE 65536

#define get_int_chars(i) ((i == 0) ? 1 : floor(log10(abs(i))) + 1)



// [[Rcpp::export]]
void
generate_bxi(const std::string& bamFile){
  int c = 0;
  int rc = 0;
  samFile *input_file = 0;
  bam_args_t bam_args;
  int max_rows = 0;
  offset_list_t *offset_list = NULL;

  bam_args.index_file_name = NULL;
  bam_args.bx = NULL;
  bam_args.convert_to = BAMDB_CONVERT_TO_TEXT;
  // the following command is for the -t parameter and the "sqlite" string that is passed to it.
  bam_args.convert_to = BAMDB_CONVERT_TO_SQLITE;
  // the following command is for the -f parameter.
  strcpy(bam_args.input_file_name, bamFile.c_str());

  input_file = sam_open(bam_args.input_file_name, "r");

  if (bam_args.convert_to == BAMDB_CONVERT_TO_SQLITE) {
    //rc = convert_to_sqlite(input_file, NULL, max_rows);
  }
}