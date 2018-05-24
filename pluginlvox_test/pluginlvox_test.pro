TEMPLATE = subdirs

SUBDIRS += grid_neighbors \
    loadscene \
    filterpoints \
    grid_merge

unix {
    SUBDIRS *= scanners
}
