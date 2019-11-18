#!/bin/bash
# Code coverage summary
# Run it after 'make test'

# Setup
BUILD_DIR='build'
PROJECTS_TO_BE_TESTED='TowerOfHanoiLib'
RESULT_FILE='code_coverage_result.log'

# Initialize
echo > $RESULT_FILE

# Run
for PROJECT in $PROJECTS_TO_BE_TESTED
do
  PROJECT_COVERAGE_DIR=$BUILD_DIR/$PROJECT/CMakeFiles/$PROJECT.dir/source/
  for COVERAGE_FILE in `find $PROJECT_COVERAGE_DIR | egrep '\.gcno'`;
  do
    gcov -n -f $COVERAGE_FILE >> $RESULT_FILE
  done
done