#!/bin/bash

# Spike 시뮬레이터 실행 명령어
spike_command="./spike"

# 응용 프로그램 목록
applications=("CCa" "CCe" "CCh" "CCh_st" "CCl" "CCm" "CF1" "CRd" "CRf" "CRm" "CS1" "CS3" "DP1d" "DP1f" "DPcvt" "DPT" "DPTd" "ED1" "EF" "EI" "EM1" "EM5" "M_Dyn" "MC" "MCS" "MD" "MI" "MIM" "MIM2" "MIP" "ML2" "ML2_BW_ld" "ML2_BW_ldst" "ML2_BW_st" "ML2_st" "MM" "MM_st" "STc" "STL2" "STL2b")

# 결과를 저장할 파일 경로
output_file="../riscv-isa-sim/goal2.txt"
test_file="../riscv-isa-sim/test.txt"

# 캐시 구성 목록
cache_configs=("1:256:64" "2:128:64" "4:64:64" "8:32:64" "16:16:64" "32:8:64" "64:4:64" "128:2:64" "256:1:64")

# 결과 파일 초기화
echo -n "" > $output_file
echo -n "" > $test_file

# 응용 프로그램별 가장 낮은 miss rate 및 해당 캐시 구성 저장 배열
declare -A lowest_miss_rates
declare -A lowest_configs

# 캐시 구성 비교
for app in "${applications[@]}"
do
  echo "Running application: $app"
  
  # 응용 프로그램별 가장 낮은 miss rate 및 캐시 구성 초기화
  lowest_miss_rate=200.0
  lowest_config=""
  
  # Spike 시뮬레이터 실행 및 결과 추출
  for config in "${cache_configs[@]}"
  do
    result=$($spike_command --dc=$config ~swe3005/2023s/proj3/pk ~swe3005/2023s/proj3/bench/$app.elf | grep "D\$ Miss Rate")
    miss_rate=$(echo $result | awk '{print $4}' | tr -d '%')
    
    # 현재 응용 프로그램의 가장 낮은 miss rate 및 캐시 구성 업데이트
    if (( $(bc <<<"$miss_rate < $lowest_miss_rate") ))
    then
      lowest_miss_rate=$miss_rate
      lowest_config=$config
    fi

    # test.txt에 출력합니다
    echo "$app --dc=$config $miss_rate%" >> $test_file
  done
  
  # 결과를 파일에 추가
  echo "$app --dc=$lowest_config $lowest_miss_rate%" >> $output_file
  echo "" >> $test_file

  echo "Finished application: $app"
  echo
done

echo "All applications processed."
