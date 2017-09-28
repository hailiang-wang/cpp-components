cc_binary(name = 'tlog',
    srcs = ['tlog.cc'],
    deps = [
        '//Common/Base:Base',
        '//Common/ThirdParty/gperftools-2.0/src:tcmalloc_minimal',
    ],
    optimize = ['O3'],
    extra_cppflags = ['-fno-omit-frame-pointer','-Wl,--eh-frame-hdr', '-ltcmalloc'],
)
