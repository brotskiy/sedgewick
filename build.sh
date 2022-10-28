cd sedgewick_tasks
mkdir -p build
pushd build
CPU_COUNT=$(grep ^cpu\\scores /proc/cpuinfo | uniq |  awk '{print $4}')
cmake .. && make -j${CPU_COUNT} && sudo ldconfig
popd