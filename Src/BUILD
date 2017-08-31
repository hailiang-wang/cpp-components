cc_library(
  name = 'KVSchedule',
  srcs = [
        'KVSchedule.cc',
  ],
  deps = [
    '//Common/Base:Base',
  ],
  extra_cppflags = ['-std=c++11', '-pthread']
)

cc_binary(name = 'KVTest',
    srcs = ['KVTest.cc'],
    deps = [
        ':KVSchedule',
        '//Common/Base:Base',
        '//Common/ThirdParty/gperftools-2.0/src:tcmalloc_minimal',
        '//Common/Util/Thread:thread',
    ],
    optimize = ['O3'],
    extra_cppflags = ['-fno-omit-frame-pointer','-Wl,--eh-frame-hdr', '-ltcmalloc'],
)