#ifndef SCHEDULING_POLICY_H
#define SCHEDULING_POLICY_H

#include <unordered_map>

#include "scheduling_queue.h"
#include "scheduling_resources.h"

namespace ray {

/// \class SchedulingPolicy
/// \brief Implements a scheduling policy for the node manager.
class SchedulingPolicy {
public:
  /// \brief SchedulingPolicy constructor.
  /// \param sched_queue: reference to a scheduler queues object for access to
  ///        tasks.
  /// \return None.
  SchedulingPolicy(const SchedulingQueue &sched_queue);

  /// Perform a scheduling operation, given a set of cluster resources and
  /// producing a mapping of tasks to node managers.
  ///  \param cluster_resources: a set of cluster resources representing
  ///        configured and current resource capacity on each node.
  /// \return Scheduling decision, mapping tasks to node managers for placement.
  std::unordered_map<TaskID, ClientID, UniqueIDHasher> Schedule(
      const std::unordered_map<ClientID, SchedulingResources, UniqueIDHasher>
          &cluster_resources);

  /// \brief SchedulingPolicy destructor.
  virtual ~SchedulingPolicy();

private:
  /// An immutable reference to the scheduling task queues.
  const SchedulingQueue &sched_queue_;
};

} // namespace ray

#endif // SCHEDULING_POLICY_H
