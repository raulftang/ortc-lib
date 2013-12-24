#!/bin/sh
echo "Please enter your android ndk path:"
echo "For example:/home/astro/android-ndk-r8e"
read Input
echo "You entered:$Input"

echo "----------------- Exporting the android-ndk path ----------------"

#Set path
export PATH=$PATH:$Input:$Input/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/bin

#build all modules
echo "******************BUILD STARTED FOR ALL ORTC LIBS*******************"

#boost build -- 1
pushd `pwd`
cd ./../../libs/boost/projects
./build_boost_android.sh $Input
popd

#openssl build -- 2
pushd `pwd`
cd ./../../libs/openssl/projects/android
./build-libssl_android.sh $Input
popd

#curl build -- 3
pushd `pwd`
cd ./../../libs/curl/projects/android
./build_curl_android.sh $Input
popd

#cryptopp build -- 4
pushd `pwd`
cd ./../../libs/cryptopp/projects/android-patches
./build_cryptopp_android.sh $Input
popd

#udns build -- 5
pushd `pwd`
cd ./../../libs/udns/projects/android
./build_udns_android.sh $Input
popd

#zsLib build -- 6
pushd `pwd`
cd ./../../libs/zsLib/projects/android
./build_zsLib_android.sh $Input
popd

#op-services-cpp build -- 7
pushd `pwd`
cd ./../../libs/op-services-cpp/projects/android
./build_op-services-cpp_android.sh $Input
popd

#webrtc build -- 8
pushd `pwd`
cd ./../../libs/webrtc/projects/android
./build_webrtc_android.sh $Input
popd

#ortc-lib build -- 9
pushd `pwd`
./build_ortclib_android.sh $Input
popd

#ortc-test sharedlib build - 10
pushd `pwd`
cd ./../android-test
./build_ortclibtest_android.sh $Input
popd

echo "******************BUILD COMLETED FOR ALL ORTC LIBS*******************"



