/**
 * @brief Header for materialization plan node.
 *
 * Copyright(c) 2015, CMU
 */

#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "common/types.h"
#include "planner/abstract_plan_node.h"

namespace nstore {

namespace catalog {
class Schema;
}

namespace planner {

class MaterializationNode : public AbstractPlanNode {
 public:
  MaterializationNode(const MaterializationNode &) = delete;
  MaterializationNode& operator=(const MaterializationNode &) = delete;
  MaterializationNode(MaterializationNode &&) = delete;
  MaterializationNode& operator=(MaterializationNode &&) = delete;


  MaterializationNode(
      const std::unordered_map<oid_t, oid_t> &old_to_new_cols,
      catalog::Schema *schema)
    : old_to_new_cols_(old_to_new_cols),
      schema_(schema) {
  }

  inline const std::unordered_map<oid_t, oid_t>& old_to_new_cols() const {
    return old_to_new_cols_;
  }

  inline const catalog::Schema& schema() const {
    return *schema_;
  }

  inline PlanNodeType GetPlanNodeType() const {
    //TODO Implement.
    return PLAN_NODE_TYPE_INVALID;
  }

  inline std::string GetInfo() const {
    //TODO Implement.
    return "";
  }

 private:
  /**
   * @brief Mapping of old column ids to new column ids after materialization.
   */
  std::unordered_map<oid_t, oid_t> old_to_new_cols_;

  /** @brief Schema of newly materialized tile. */
  std::unique_ptr<catalog::Schema> schema_;
};

} // namespace planner
} // namespace nstore
