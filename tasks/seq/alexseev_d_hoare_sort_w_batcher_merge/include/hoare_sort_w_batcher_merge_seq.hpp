// Copyright 2024 Alexseev Danila
#pragma once

#include <string>
#include <vector>

#include "core/task/include/task.hpp"

class HoareSortWBatcherMergeSequential : public ppc::core::Task {
 public:
  explicit HoareSortWBatcherMergeSequential(std::shared_ptr<ppc::core::TaskData> taskData_)
      : Task(std::move(taskData_)) {}
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;
  void HoareSortWBatcherMergeSeq(std::vector<int> &arr, size_t l, size_t r);
  static void CompExch(int &a, int &b);

 private:
  std::vector<int> array{};
};

std::vector<int> generateRandomVector(int size, int minVal, int maxVal);
