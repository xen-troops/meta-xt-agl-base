# for Wayland/Weston weston-laucher
DISTRO_FEATURES_append = " pam"

# For virtualization
DISTRO_FEATURES_append = " virtualization"

# For v4l2-renderer
# DISTRO_FEATURES_append = " v4l2-renderer"

# For pulseaudio
DISTRO_FEATURES_append = " pulseaudio"

# Enable Gfx Pkgs
MACHINE_FEATURES_append = " gsx"
MULTI_PROVIDER_WHITELIST += "virtual/libgl virtual/egl virtual/libgles1 virtual/libgles2"

AGL_EXTRA_IMAGE_FSTYPES = "ext4 tar.bz2"

# for Wayland/Weston
PREFERRED_PROVIDER_virtual/libgles1 = ""
PREFERRED_PROVIDER_virtual/libgles2 = "gles-user-module"
PREFERRED_PROVIDER_virtual/egl = "gles-user-module"
PREFERRED_PROVIDER_virtual/libgl = ""
PREFERRED_PROVIDER_virtual/mesa = "mesa"
PREFERRED_PROVIDER_libgbm = "libgbm"
PREFERRED_RPROVIDER_libgbm-dev = "libgbm"

# Mask the gstreamer recipe for MMP
BBMASK = "meta-renesas/meta-rcar-gen3/recipes-multimedia/gstreamer"

# Add for gstreamer plugins ugly
LICENSE_FLAGS_WHITELIST = "commercial"

PREFERRED_VERSION_gstreamer1.0-plugins-vspfilter = "1.0%"

DISTRO_FEATURES_append = " h264dec_lib h264enc_lib aaclcdec_lib aaclcdec_mdw"

DISTRO_FEATURES_BACKFILL_remove = "gobject-introspection-data"

IMAGE_INSTALL_append_rcar-gen3 = " \
	kernel-module-pvrsrvkm \
"

SECURITY_CFLAGS_pn-xen = ""
SECURITY_CFLAGS_pn-gles-user-module = ""

BBMASK .= "|meta-renesas-rcar-gen3/meta-rcar-gen3/recipes-forward-port/"
# FIXME: this recipe makes problems during recipe parsing
BBMASK .= "|meta-virtualization/recipes-containers/docker"

# remove OMX and dependecies
BBMASK .= "|kernel-module-uvcs-drv|omx-user-module|gstreamer1.0-omx"

# Provide own ALSA configuration
BBMASK .= "|meta-rcar-gen3/recipes-bsp/alsa-state/alsa-state.bbappend"

# Provide own pulseaudio configuration
BBMASK .= "|meta-agl-devel/ATTIC/meta-audio-4a-framework/recipes-multimedia/pulseaudio/pulseaudio_%.bbappend"
BBMASK .= "|bsp/meta-rcar/meta-rcar-gen3-adas/recipes-multimedia/pulseaudio/pulseaudio_12_2.bbappend"
BBMASK .= "|meta-agl/meta-agl-profile-core/recipes-multimedia/pulseaudio/pulseaudio_%.bbappend"

OSTREE_BOOTLOADER ?= "u-boot"
BB_DANGLINGAPPENDS_WARNONLY = "yes"
