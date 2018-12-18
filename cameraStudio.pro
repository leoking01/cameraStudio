#-------------------------------------------------
#
# Project created by QtCreator 2018-07-13T21:58:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cameraStudio
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui



#LIBS += -LD:/env/opencv341Vs2015Cud8Ana35/install/x64/vc14/lib/ \
#-lopencv_aruco341d   \
#-lopencv_bgsegm341d   \
#-lopencv_bioinspired341d   \
#-lopencv_calib3d341d   \
#-lopencv_ccalib341d   \
#-lopencv_core341d   \
#-lopencv_cudaarithm341d   \
#-lopencv_cudabgsegm341d   \
#-lopencv_cudacodec341d   \
#-lopencv_cudafeatures2d341d   \
#-lopencv_cudafilters341d   \
#-lopencv_cudev341d   \
#-lopencv_datasets341d   \
#-lopencv_dnn_objdetect341d   \
#-lopencv_dnn341d   \
#-lopencv_dpm341d   \
#-lopencv_face341d   \
#-lopencv_features2d341d   \
#-lopencv_flann341d   \
#-lopencv_fuzzy341d   \
#-lopencv_hdf341d   \
#-lopencv_hfs341d   \
#-lopencv_highgui341d   \
#-lopencv_img_hash341d   \
#-lopencv_imgcodecs341d   \
#-lopencv_imgproc341d   \
#-lopencv_line_descriptor341d   \
#-lopencv_ml341d   \
#-lopencv_objdetect341d   \
#-lopencv_optflow341d   \
#-lopencv_phase_unwrapping341d   \
#-lopencv_photo341d   \
#-lopencv_reg341d   \
#-lopencv_saliency341d   \
#-lopencv_shape341d   \
#-lopencv_stereo341d   \
#-lopencv_stitching341d   \
#-lopencv_structured_light341d   \
#-lopencv_superres341d   \
#-lopencv_surface_matching341d   \
#-lopencv_text341d   \
#-lopencv_tracking341d   \
#-lopencv_video341d   \
#-lopencv_videoio341d   \
#-lopencv_videostab341d   \
#-lopencv_xfeatures2d341d   \
#-lopencv_ximgproc341d   \
#-lopencv_xobjdetect341d   \
#-lopencv_xphoto341d
##else:unix: LIBS += -L$$PWD/../../../env/opencv341Vs2015Cud8Ana35/install/x64/vc14/lib/ -lopencv_ccalib341

#INCLUDEPATH += D:/env/opencv341Vs2015Cud8Ana35/install/include
#DEPENDPATH += D:/env/opencv341Vs2015Cud8Ana35/install/include


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../win10/env/opencv341/build/x64/vc14/lib/ -lopencv_world341
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../win10/env/opencv341/build/x64/vc14/lib/ -lopencv_world341d
else:unix: LIBS += -L$$PWD/../../../../../win10/env/opencv341/build/x64/vc14/lib/ -lopencv_world341

INCLUDEPATH += $$PWD/../../../../../win10/env/opencv341/build/include
DEPENDPATH += $$PWD/../../../../../win10/env/opencv341/build/include






