/*
*                         Vortex Lite
*
*   This software and documentation are Copyright 2006 to 2015 PrismTech
*   Limited and its licensees. All rights reserved. See file:
*
*                     $LITE_HOME/LICENSE
*
*   for full copyright notice and license terms.
*
*/


/**
 * @file
 */

#ifndef CYCLONEDDS_TOPIC_TOPICDESCRIPTIONDELEGATE_HPP_
#define CYCLONEDDS_TOPIC_TOPICDESCRIPTIONDELEGATE_HPP_

#include <dds/domain/DomainParticipant.hpp>
#include <org/eclipse/cyclonedds/core/ObjectDelegate.hpp>

namespace org
{
namespace eclipse
{
namespace cyclonedds
{
namespace topic
{

class OMG_DDS_API TopicDescriptionDelegate : public virtual org::eclipse::cyclonedds::core::ObjectDelegate
{
public:
    typedef ::dds::core::smart_ptr_traits< TopicDescriptionDelegate >::ref_type ref_type;
    typedef ::dds::core::smart_ptr_traits< TopicDescriptionDelegate >::weak_ref_type weak_ref_type;

public:
    TopicDescriptionDelegate(const dds::domain::DomainParticipant& dp,
                             const std::string& name,
                             const std::string& type_name);
    virtual ~TopicDescriptionDelegate();

public:

    /**
     *  @internal Get the name used to create the TopicDescription.
     */
    const std::string& name() const;

    /**
     *  @internal The type_name used to create the TopicDescription.
     */
    const std::string& type_name() const;

    /**
     *  @internal This operation returns the DomainParticipant to which the
     * TopicDescription belongs.
     */
    const dds::domain::DomainParticipant& domain_participant() const;

    void incrNrDependents();

    void decrNrDependents();

    bool hasDependents() const;

    virtual std::string reader_expression() const = 0;

    //@todo virtual c_value *reader_parameters() const = 0;

protected:
    dds::domain::DomainParticipant myParticipant;
    std::string myTopicName;
    std::string myTypeName;
    uint32_t nrDependents;
};

}
}
}
}

#endif /* CYCLONEDDS_TOPIC_TOPICDESCRIPTIONDELEGATE_HPP_ */
