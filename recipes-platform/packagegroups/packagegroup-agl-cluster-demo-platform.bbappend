RDEPENDS_${PN}_remove = " \
    connman \
    connman-client \
    connman-tests \
    connman-tools \
    connman-ncurses \
    connman-conf \
    connman-gnome \
    cluster-connman-conf \
    libconnman-qt5_git \
    ${AGL_APPS} \
"

RDEPENDS_${PN}_append = " \
    cluster-dashboard-vis \
"
