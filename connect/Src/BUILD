cc_binary(name = 'Connect',
    srcs = ['connect.cc'],
    deps = [
        '//Common/Base:Base',
        '//Common/ThirdParty/gperftools-2.0/src:tcmalloc_minimal',
    ],
    optimize = ['O3'],
    extra_cppflags = ['-fno-omit-frame-pointer','-Wl,--eh-frame-hdr', '-ltcmalloc', '-std=c++14'],
)
